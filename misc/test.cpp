#include "vec3.h"
#include <Windows.h>
#include <fstream>
#include <gl\GL.h>
#include <gl\GLU.h>
#include <gl\glut.h>
#include <math.h>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define kWindowWidth 800
#define kWindowHeight 600

using namespace std;

float xrot = 0.0f;
float yrot = 0.0f;
float zrot = 0.0f;
float xrotspeed = 0.5f;
float yrotspeed = 0.4f;
float zrotspeed = 0.0f;

float curx = 0, cury = 0, curz = 0;

bool arcball_on = false;
bool mouse_down = false;
int xDown = 0, yDown = 0;
int xrotStart = 0, yrotStart = 0;
float scale = 1.0f;
struct Triangle {
  Triangle() {}
  Triangle(int v0, int v1, int v2) {
    v[0] = v0;
    v[1] = v1;
    v[2] = v2;
    // t[3] = { -1 };
  }
  Triangle(int v0, int v1, int v2, vec3 n_) {
    v[0] = v0;
    v[1] = v1;
    v[2] = v2;
    // t[3] = { -1 };
    n = n_;
  }

  int v[3];
  int t[3] = {-1};
  vec3 n;
};

struct Edge {
  int t0 = -1;
  int t1 = -1;
};

struct Object {
  Object() {}
  vector<vec3> pts;
  vector<Triangle> trs;
  unordered_map<int, unordered_set<int>> vertex_map;
  // unordered_map<int, vector<int>> vertices_map;
  // unordered_map<string, Edge> edge_map;
};

void getfilename(const string &filepath, string &filename) {
  size_t found = filepath.find_last_of('/\\');
  filename = filepath.substr(found + 1);
}

struct SimplePoint {
  SimplePoint() {}
  SimplePoint(vec3 c_, int ind_) : c(c_), ind(ind_) {}
  vec3 c;
  int ind;
};

static void loop3(Object &obj) {
  int p = obj.pts.size();

  // vector<vec3> even_vertex;
  // even_vertex.resize(p);
  vector<vec3> new_pts;

  // even vertex;
  for (int i = 0; i < p; ++i) {
    int k = obj.vertex_map[i].size();
    float beta;
    if (k == 3)
      beta = 0.1875f;
    else if (k > 3)
      beta = 3.0f / (8.0f * k);
    // beta = 1.0f / k*(5.0f / 8 - (3.0f / 8 + 1.0f / 4 * square(cosf(2.0f*pi /
    // k))));

    vec3 surrounding;

    for (auto &vp : obj.vertex_map[i]) {
      surrounding += obj.pts[vp];
    }
    // even_vertex[i] = obj.pts[i] * (1.0f - k * beta) + surrounding * beta;
    new_pts.emplace_back((1.0f - k * beta) * obj.pts[i] + surrounding * beta);
  }

  vector<Triangle> new_trs;

  // odd vertex
  unordered_map<string, SimplePoint> edge_points;
  int s = obj.trs.size();

  int count_ind = p - 1;

  unordered_map<int, unordered_set<int>> vertex_map;
  vec3 odd_vertex[3];
  int odd_ind[3];
  for (int i = 0; i < s; ++i) {
    for (int j = 0; j < 3; ++j) // 3 canh
    {
      int v0 = obj.trs[i].v[j];
      int v1 = obj.trs[i].v[(j + 1) % 3];
      // int v2 = obj.trs[i].v[(j + 2) % 3];
      string s0 = to_string(v0), s1 = to_string(v1);
      string s01 = s0 + "|" + s1;
      string s10 = s1 + "|" + s0;

      if (edge_points.find(s10) != edge_points.end()) {
        odd_vertex[j] = edge_points[s10].c;
        odd_ind[j] = edge_points[s10].ind;
      } else {
        // edge_points[s01]
        int adj = obj.trs[i].t[j];
        int adj_op;
        for (int m = 0; m < 3; ++m) {
          int tmp_ind = obj.trs[adj].v[m];
          if (tmp_ind != v0 && tmp_ind != v1) {
            adj_op = tmp_ind;
            break;
          }
        }

        int cur_op = obj.trs[i].v[(j + 2) % 3];
        odd_vertex[j] = (3.0f * (obj.pts[v0] + obj.pts[v1]) +
                         (obj.pts[adj_op] + obj.pts[cur_op])) *
                        0.125f;

        // odd_vertex[j] = (0.375f * (new_pts[v0] + new_pts[v1]) + 0.125f *
        // (new_pts[adj_op] + new_pts[cur_op]));// *0.125f;

        ++count_ind;
        odd_ind[j] = count_ind;

        edge_points[s01] = {odd_vertex[j], odd_ind[j]};
        // edge_points[s10] = { odd_vertex[j], odd_ind[j] };
        new_pts.emplace_back(odd_vertex[j]);
      }
    }

    // add 4 triangles
    int v0 = obj.trs[i].v[0];
    int v1 = obj.trs[i].v[1];
    int v2 = obj.trs[i].v[2];

    vec3 n1 = (new_pts[v0] - new_pts[odd_ind[0]])
                  .cross(new_pts[v0] - new_pts[odd_ind[2]])
                  .norm();
    vec3 n2 = (new_pts[v1] - new_pts[odd_ind[1]])
                  .cross(new_pts[v1] - new_pts[odd_ind[0]])
                  .norm();
    vec3 n3 = (new_pts[v2] - new_pts[odd_ind[2]])
                  .cross(new_pts[v2] - new_pts[odd_ind[1]])
                  .norm();
    vec3 n4 = (new_pts[odd_ind[0]] - new_pts[odd_ind[1]])
                  .cross(new_pts[odd_ind[0]] - new_pts[odd_ind[2]])
                  .norm();

    Triangle tr1(v0, odd_ind[0], odd_ind[2], n1);
    Triangle tr2(v1, odd_ind[1], odd_ind[0], n2);
    Triangle tr3(v2, odd_ind[2], odd_ind[1], n3);
    Triangle tr4(odd_ind[0], odd_ind[1], odd_ind[2], n4);

    new_trs.emplace_back(tr1);
    new_trs.emplace_back(tr2);
    new_trs.emplace_back(tr3);
    new_trs.emplace_back(tr4);
  }

  // vector<vec3>().swap(obj.pts);
  // vector<Triangle>().swap(obj.trs);
  obj.pts = new_pts;
  obj.trs = new_trs;
  update_adjacent_triangle(obj);
}

GLfloat r, ang, dang, rot = 0, drot = 1.45f;

GLfloat lightAmbient[] = {0.0f, 0.0f, 0.0f, 1.0f};
GLfloat lightDiffuse[] = {1.0f, 1.0f, 1.0f, 1.0f};
GLfloat lightSpecular[] = {0.2f, 0.2f, 0.2f, 1.0f};
GLfloat lightPosition[] = {50.0f, -40.0f, -20.0f, 1.0f};
GLfloat materialAmbient[] = {0.0f, 0.0f, 0.0f, 1.0f};
GLfloat materialDiffuse[] = {0.5f, 0.6f, 1.0f, 1.0f};
GLfloat materialSpecular[] = {0.1f, 0.1f, 0.1f, 1.0f};

GLvoid InitGL(GLvoid) {
  glClearColor(0.1f, 0.2f, 0.5f, 0.0f);
  glClearDepth(1.0);
  glDepthFunc(GL_LESS);
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_NORMALIZE);
  glShadeModel(GL_SMOOTH);

  glLightfv(GL_LIGHT1, GL_AMBIENT, lightAmbient);
  glLightfv(GL_LIGHT1, GL_DIFFUSE, lightDiffuse);
  // glLightfv(GL_LIGHT1, GL_SPECULAR, lightSpecular);
  glLightfv(GL_LIGHT1, GL_POSITION, lightPosition);
  glEnable(GL_LIGHT1);
  glEnable(GL_LIGHTING);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  gluPerspective(45.0f, (GLfloat)kWindowWidth / (GLfloat)kWindowHeight, 0.1f,
                 100.0f);
  glMatrixMode(GL_MODELVIEW);
}

GLvoid ReSizeGLScene(int Width, int Height) {
  glViewport(0, 0, (GLsizei)Width, (GLsizei)Height);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  gluPerspective(45.0, (GLfloat)Width / (GLfloat)Height, 0.1, 100.0);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

Object obj;

GLvoid DrawGLScene(GLvoid) {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();
  // glEnable(GL_FRONT);
  // glFrontFace(GL_CW);
  glTranslatef(0.0f, 0.0f, -10.0f);

  glRotatef(xrot, 1.0f, 0.0f, 0.0f);
  glRotatef(yrot, 0.0f, 1.0f, 0.0f);
  glRotatef(zrot, 0.0f, 0.0f, 1.0f);

  glScalef(scale, scale, scale);
  // if (arcball_on)
  //{
  // if (xrotspeed || yrotspeed || zrotspeed)
  //{
  if (mouse_down) {
    xrot += xrotspeed;
    yrot += yrotspeed;
    zrot += zrotspeed;
  }
  //}

  // glMultMatrixf(rotation_matrix);

  glBegin(GL_TRIANGLES);
  glColor3f(1.0f, 1.0f, 1.0f);
  // glMaterialfv(GL_FRONT, GL_AMBIENT, materialAmbient);
  // glMaterialfv(GL_FRONT, GL_DIFFUSE, materialDiffuse);
  glMaterialfv(GL_FRONT, GL_SPECULAR, materialSpecular);

  int s = obj.trs.size();

  for (int i = 0; i < s; ++i) {
    int v0 = obj.trs[i].v[0], v1 = obj.trs[i].v[1], v2 = obj.trs[i].v[2];
    vec3 p0 = obj.pts[v0], p1 = obj.pts[v1], p2 = obj.pts[v2];
    vec3 n = obj.trs[i].n;
    glNormal3f(n.x, n.y, n.z);
    glVertex3f(p0.x, p0.y, p0.z);
    glVertex3f(p1.x, p1.y, p1.z);
    glVertex3f(p2.x, p2.y, p2.z);
  }

  glEnd();

  glFlush();
  glutSwapBuffers();
  glutPostRedisplay();
}
string filename = "star.ply";
// string filename = "icos.ply";
// string filename = "octa.ply";
// string filename = "tetra.ply";
// string filename = "torus.ply";

void Keypress(unsigned char key, int x, int y) {
  switch (key) {
  case 27:
    exit(0);
  case 32:
    if (drot == 0.25f)
      drot = 0.0f;
    else
      drot = 0.25f;
  case 82:
    //<vec3>().swap(obj.pts);
    // vector<Triangle>().swap(obj.trs);
    // unordered_map<int, unordered_set<int>>().swap(obj.vertex_map);
    Read_PLY(filename, obj);
  case 114:
    Read_PLY(filename, obj);
  case 83:
    loop3(obj);
  case 115:
    loop3(obj);
  }
}