
from mpl_toolkits.mplot3d import axes3d
import matplotlib.pyplot as plt
import numpy as np
import sys
import time
import math


def center_point(p1, p2):
    """
    returns a point in the center of the
    segment ended by points p1 and p2
    """
    cp = []
    for i in range(3):
        cp.append((p1[i] + p2[i]) / 2)

    return cp


def sum_point(p1, p2):
    """
    adds points p1 and p2
    """
    sp = []
    for i in range(3):
        sp.append(p1[i] + p2[i])

    return sp

def sub_point(p1, p2):
    sp = []
    for i in range(3):
        sp.append(p1[i] - p2[i])

    return sp

def div_point(p, d):
    """
    divide point p by d
    """
    sp = []
    for i in range(3):
        sp.append(p[i] / d)

    return sp


def mul_point(p, m):
    """
    multiply point p by m
    """
    sp = []
    for i in range(3):
        sp.append(p[i] * m)

    return sp


def get_edges_faces(input_points, input_faces):
    """

    Get list of edges and the one or two adjacent faces in a list.
    also get center point of edge

    Each edge would be [pointnum_1, pointnum_2, facenum_1, facenum_2, center]

    """

    # will have [pointnum_1, pointnum_2, facenum]

    edges = []

    # get edges from each face

    for facenum in range(len(input_faces)):
        face = input_faces[facenum]
        num_points = len(face)
        # loop over index into face
        for pointindex in range(num_points):
            # if not last point then edge is curr point and next point
            if pointindex < num_points - 1:
                pointnum_1 = face[pointindex]
                pointnum_2 = face[pointindex + 1]
            else:
                # for last point edge is curr point and first point
                pointnum_1 = face[pointindex]
                pointnum_2 = face[0]
            # order points in edge by lowest point number
            if pointnum_1 > pointnum_2:
                temp = pointnum_1
                pointnum_1 = pointnum_2
                pointnum_2 = temp
            edges.append([pointnum_1, pointnum_2, facenum])

    # sort edges by pointnum_1, pointnum_2, facenum

    edges = sorted(edges)

    # merge edges with 2 adjacent faces
    # [pointnum_1, pointnum_2, facenum_1, facenum_2] or
    # [pointnum_1, pointnum_2, facenum_1, None]

    num_edges = len(edges)
    eindex = 0
    merged_edges = []

    while eindex < num_edges:
        e1 = edges[eindex]
        # check if not last edge
        if eindex < num_edges - 1:
            e2 = edges[eindex + 1]
            if e1[0] == e2[0] and e1[1] == e2[1]:
                merged_edges.append([e1[0], e1[1], e1[2], e2[2]])
                eindex += 2
            else:
                merged_edges.append([e1[0], e1[1], e1[2], None])
                eindex += 1
        else:
            merged_edges.append([e1[0], e1[1], e1[2], None])
            eindex += 1

    # add edge centers

    edges_centers = []

    for me in merged_edges:
        p1 = input_points[me[0]]
        p2 = input_points[me[1]]
        cp = center_point(p1, p2)
        edges_centers.append(me + [cp])

    return edges_centers

def get_faces_points(input_points, input_faces, edges_faces):
    num_edges = len(edges_faces)
    faces_points = []

    for edge in edges_faces:
        if edge[3] != None:
            faces_point = [0.0, 0.0, 0.0]
            for face_num in [edge[2],edge[3]]:
                for point_num in input_faces[face_num]:
                    if point_num != edge[0] and point_num != edge[1]:
                        faces_point = sum_point(faces_point,mul_point(input_points[point_num], 0.25))
                    else:
                        faces_point = sum_point(faces_point,mul_point(input_points[point_num], 0.125))
            faces_points.append(faces_point)
            print(faces_point)
        else:
            faces_point = [0.0, 0.0, 0.0]
            faces_points.append(faces_point)

    return faces_points


def get_edge_points(edges_faces, faces_points):
    edge_points = []
    for i in range(len(edges_faces)):
        if edges_faces[i][3] != None:
            edge_points.append(center_point(edges_faces[i][4], faces_points[i]))
        else:
            edge_points.append(edges_faces[i][4])

    return edge_points


def get_points_faces(input_points, input_faces):
    # initialize list with 0

    num_points = len(input_points)

    points_faces = []

    for pointnum in range(num_points):
        points_faces.append([0,[]])

    # loop through faces updating points_faces

    for facenum in range(len(input_faces)):
        for pointnum in input_faces[facenum]:
            points_faces[pointnum][0] += 1
            points_faces[pointnum][1].append(facenum)

    return points_faces
#统计每个点属于多少个面

def get_face_sum(input_points, input_faces):
    face_sum = []
    for face in input_faces:
        p = sum_point(input_points[face[2]],sum_point(input_points[face[0]],input_points[face[1]]))
        face_sum.append(p)
    return face_sum

def get_new_points(input_points, points_faces, face_sum):
    new_points = []

    for i in range(len(input_points)):
        q = [0.0, 0.0, 0.0]
        beta = 5.0/8-pow(3.0/8+1.0/4*math.cos(2*math.pi/points_faces[i][0]),2)
        for point_face_num in points_faces[i][1]:
            q = sum_point(q, face_sum[point_face_num])
        q = sub_point(q, mul_point(input_points[i], points_faces[i][0]))
        q = div_point(q, 2*points_faces[i][0])
        v = mul_point(input_points[i],1-1*beta)
        new_points.append(sum_point(v, mul_point(q, 1*beta)))

    return new_points


def switch_nums(point_nums):
    """
    Returns tuple of point numbers
    sorted least to most
    """
    if point_nums[0] < point_nums[1]:
        return point_nums
    else:
        return (point_nums[1], point_nums[0])

def loop_subdiv(input_points, input_faces):
    edges_faces = get_edges_faces(input_points, input_faces)

    faces_points = get_faces_points(input_points, input_faces, edges_faces)
    #print(len(faces_points))
    edge_points = get_edge_points(edges_faces, faces_points)

    print(edge_points)
    points_faces = get_points_faces(input_points, input_faces)

    face_sum = get_face_sum(input_points, input_faces)

    new_points = get_new_points(input_points, points_faces, face_sum)

    next_pointnum = len(new_points)
    edge_point_nums = dict()

    for edgenum in range(len(edges_faces)):
        pointnum_1 = edges_faces[edgenum][0]
        pointnum_2 = edges_faces[edgenum][1]
        edge_point = edge_points[edgenum]
        new_points.append(edge_point)
        edge_point_nums[(pointnum_1, pointnum_2)] = next_pointnum
        next_pointnum += 1

    new_faces = []

    for oldfacenum in range(len(input_faces)):
        oldface = input_faces[oldfacenum]
        # 3 point face
        if len(oldface) == 3:
            a = oldface[0]
            b = oldface[1]
            c = oldface[2]

            edge_point_ab = edge_point_nums[switch_nums((a, b))]
            edge_point_ca = edge_point_nums[switch_nums((c, a))]
            edge_point_bc = edge_point_nums[switch_nums((b, c))]

            new_faces.append((a, edge_point_ab, edge_point_ca))
            new_faces.append((b, edge_point_bc, edge_point_ab))
            new_faces.append((c, edge_point_ca, edge_point_bc))
            new_faces.append((edge_point_ca, edge_point_ab, edge_point_bc))


    return new_points, new_faces



def graph_output(output_points, output_faces, fig):

    ax = fig.add_subplot(111, projection='3d')


    """

    Plot each face

    """

    for facenum in range(len(output_faces)):
        curr_face = output_faces[facenum]
        xcurr = []
        ycurr = []
        zcurr = []
        for pointnum in range(len(curr_face)):
            xcurr.append(output_points[curr_face[pointnum]][0])
            ycurr.append(output_points[curr_face[pointnum]][1])
            zcurr.append(output_points[curr_face[pointnum]][2])
        xcurr.append(output_points[curr_face[0]][0])
        ycurr.append(output_points[curr_face[0]][1])
        zcurr.append(output_points[curr_face[0]][2])

        ax.plot(xcurr, ycurr, zcurr, color='b')


input_points = [
    [-1.0, 1.0, 1.0],
    #[-1.0, -1.0, 1.0],
    [1.0, -1.0, 1.0],
    #[1.0, 1.0, 1.0],
    #[1.0, -1.0, -1.0],
    [1.0, 1.0, -1.0],
    [-1.0, -1.0, -1.0],
    #[-1.0, 1.0, -1.0]
]

'''input_faces = [
    [0, 1, 2, 3],
    [3, 2, 4, 5],
    [5, 4, 6, 7],
    [7, 0, 3, 5],
    [7, 6, 1, 0],
    [6, 1, 2, 4],
]'''

input_faces = [
    [0, 3, 1],
    [0, 3, 2],
    [0, 2, 1],
    [3, 2, 1],
]


iterations = 4

plt.ion()
output_points, output_faces = input_points, input_faces


for i in range(iterations):
    output_points, output_faces = loop_subdiv(output_points, output_faces)
    fig = plt.figure(1)
    plt.clf()
    graph_output(output_points, output_faces, fig)
    plt.pause(1)
