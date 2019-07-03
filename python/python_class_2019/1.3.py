# -*- coding: utf-8 -*-
#利用numpy模块构造幻方
import numpy as np

#列表循环向左移offset位
def shift_left(lst, offset):
    return [lst[(i+offset)%len(lst)] for i in range(len(lst))]

#列表循环向右移offset位
def shift_right(lst, offset):
    return [lst[i-offset] for i in range(len(lst))]

#构造奇数阶幻方函数
def magic_of_odd_order(n):
    p = (int)((n-1)/2)

    #创建矩阵1
    initial_lst1 = list(range(p+1,n))+list(range(p+1))
    initial_mat1 = []
    for i in range(n):
        initial_mat1.append(shift_left(initial_lst1, i))
    mat1 = np.array(initial_mat1)

    #创建矩阵2
    initial_lst2 = list(range(p,-1,-1))+list(range(2*p,p,-1))
    initial_mat2 = []
    for i in range(n):
        initial_mat2.append(shift_right(initial_lst2, i))
    mat2 = np.array(initial_mat2)

    #创建矩阵3,即元素全为1的矩阵
    mat3= np.ones((n,n),dtype=np.int)

    #构造幻方
    magic = n*mat2+mat1+mat3
    return magic

#构造4n阶幻方函数
def magic_of_4n_order(n):
    mat = np.array(range(1,n*n+1)).reshape(n,n)
    for i in range((int)(n/4)):
        for j in range((int)(n/4)):
            for k in range(4): #将每个4*4小方块的对角线换成互补元素
                mat[k+4*j][k+4*i] = n*n+1-mat[k+4*j][k+4*i]
                mat[k+4*j][3-k+4*i] = n*n+1-mat[k+4*j][3-k+4*i]

    return mat

#构造4n+2阶幻方函数
def magic_of_4n2_order(n):
    p = (int)(n/2)
    matA = magic_of_odd_order(p)
    matD = matA+p**2
    matB = matD+p**2
    matC = matB+p**2

    #交换矩阵块A与矩阵块C中特定元素的位置
    row = (int)((p-1)/2)
    for i in range(p):
        if i != row:
            for k in range((int)((n-2)/4)):
                matA[i][k],matC[i][k] = matC[i][k],matA[i][k]
        else:
            for k in range((int)((n-2)/4)):
                matA[i][row+k],matC[i][row+k] = matC[i][row+k],matA[i][row+k]

    #交换矩阵块B与矩阵块D中特定元素的位置
    col = (int)((p-1)/2)
    for j in range(col+2-(int)((n-2)/4),col+1):
        for i in range(p):
            matB[i][j],matD[i][j] = matD[i][j],matB[i][j]

    #合并矩阵块A,B,C,D组成幻方
    magic = np.row_stack((np.column_stack((matA,matB)),np.column_stack((matC,matD))))
    return magic

def fun():
    order = eval(input('Enter the order of magic square(>=3): '))

    if order%2 ==1:
        magic = magic_of_odd_order(order)
    elif order%4 == 0:
        magic = magic_of_4n_order(order)
    else:
        magic = magic_of_4n2_order(order)
    print('Generating magic square of %d order......'%order)

    for row in magic:
        for col in row:
            print(col, end='\t')
        print()

    #验证生成的magic是否为幻方
    val = input(("Do you want to validate?[Y|N]"))
    if val == 'Y' or val == 'y':
        print('每行的和:', np.sum(magic, axis=0))
        print('每列的和:', np.sum(magic, axis=1))
        print('主对角线的和:', sum([magic[i][i] for i in range(order)]))
        print('副对角线的和:', sum([magic[i][order-1-i] for i in range(order)]))
    print('It\'s Done!')

fun()