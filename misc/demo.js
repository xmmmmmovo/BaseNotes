//  Loop subdivision splines  29.03.2013

var cp = [],
  faces = [],
  ce = []; // Control Points, Edges
var lastP,
  vi = [],
  ei0 = [],
  ei = [],
  fi0 = [],
  fi = [];
var n = 5,
  vil,
  fil,
  cpl,
  cpl3,
  cel2;
var an = [],
  bn = [],
  aL = [],
  b,
  tauc = [[], [], []],
  taus = [[], [], []];

function Edge(ps) {
  this.PS = ps; // PS=[p0, p1] indexes of the first and last points of a directional edge
}
Edge.prototype.subdiv = function () {
  var i01 = lastP++,
    k = 3 * i01,
    i0 = this.PS[0],
    k0 = 3 * i0,
    i1 = this.PS[1],
    k1 = 3 * i1;
  p[k++] = 0.5 * (p[k0++] + p[k1++]);
  p[k++] = 0.5 * (p[k0++] + p[k1++]);
  p[k++] = 0.5 * (p[k0++] + p[k1++]);
  this.E00 = ei.length;
  ei.push(new Edge([i0, i01]));
  ei.push(new Edge([i01, i1]));
  var t = [];
  t[0] = [this.E00, 0];
  t[3] = [this.E00 + 1, 1];
  vi.push(t);
  this.P01 = i01; // P01, E00 - indexes of the child point and first edges
};

function Face(ed0, ed1, ed2, i0, i1, i2) {
  // face's edges with orientations
  this.E0 = ed0;
  this.E1 = ed1;
  this.E2 = ed2;
  this.I0 = i0;
  this.I1 = i1;
  this.I2 = i2;
  this.P0 = ei[ed0].PS[i0];
  this.P1 = ei[ed1].PS[i1];
  this.P2 = ei[ed2].PS[i2]; // face's points
}
Face.prototype.subdiv = function () {
  var m0 = ei0[this.E0].P01,
    m1 = ei0[this.E1].P01,
    m2 = ei0[this.E2].P01;
  var em = ei.length;
  ei.push(new Edge([m0, m1]));
  ei.push(new Edge([m1, m2]));
  ei.push(new Edge([m2, m0]));
  var ed00, ed01, ed10, ed11, ed20, ed21;
  if (this.I0 == 0) {
    vi[m0][4] = [em, 1];
    vi[m0][5] = [em + 2, 0];
    ed00 = ei0[this.E0].E00;
    ed01 = ed00 + 1;
  } else {
    vi[m0][1] = [em, 1];
    vi[m0][2] = [em + 2, 0];
    ed01 = ei0[this.E0].E00;
    ed00 = ed01 + 1;
  }
  if (this.I1 == 0) {
    vi[m1][4] = [em + 1, 1];
    vi[m1][5] = [em, 0];
    ed10 = ei0[this.E1].E00;
    ed11 = ed10 + 1;
  } else {
    vi[m1][1] = [em + 1, 1];
    vi[m1][2] = [em, 0];
    ed11 = ei0[this.E1].E00;
    ed10 = ed11 + 1;
  }
  if (this.I2 == 0) {
    vi[m2][4] = [em + 2, 1];
    vi[m2][5] = [em + 1, 0];
    ed20 = ei0[this.E2].E00;
    ed21 = ed20 + 1;
  } else {
    vi[m2][1] = [em + 2, 1];
    vi[m2][2] = [em + 1, 0];
    ed21 = ei0[this.E2].E00;
    ed20 = ed21 + 1;
  }
  fi.push(new Face(ed00, em + 2, ed21, this.I0, 1, this.I2));
  fi.push(new Face(ed10, em, ed01, this.I1, 1, this.I0));
  fi.push(new Face(ed20, em + 1, ed11, this.I2, 1, this.I1));
  fi.push(new Face(em, em + 1, em + 2, 0, 0, 0));
};

function mask() {
  for (var i = 3; i < 50; i++) {
    b = 3 / 8 + Math.cos((2 * Math.PI) / i) / 4;
    aL[i] = b * b + 3 / 8;
    an[i] = 2 * aL[i] - 1;
    bn[i] = 3 / (11 - 8 * aL[i]);
    tauc.push([]);
    taus.push([]);
    for (var j = 0; j < i; j++) {
      tauc[i].push(Math.cos((2 * Math.PI * j) / i));
      taus[i].push(Math.sin((2 * Math.PI * j) / i));
    }
  }
}
function Loop() {
  // parser

  var vior = [];
  ei = [];
  fi = [];
  vi = [];
  ce = [];
  for (var i = 0; i < cp.length / 3; i++) vior.push([]);
  for (var i = 0; i < faces.length; i += 3) {
    var a = faces[i],
      b = faces[i + 1];
    var id0 = -1,
      dir0 = 0,
      cel = ce.length;
    for (var k = 0; k < cel; k++) {
      if (a == ce[k][0] && b == ce[k][1]) id0 = k;
      if (b == ce[k][0] && a == ce[k][1]) {
        id0 = k;
        dir0 = 1;
      }
    }
    if (id0 < 0) {
      id0 = ce.length;
      ce.push([a, b]);
      ei.push(new Edge([a, b]));
    }
    a = faces[i + 1];
    b = faces[i + 2];
    var id1 = -1,
      dir1 = 0;
    cel = ce.length;
    for (var k = 0; k < cel; k++) {
      if (a == ce[k][0] && b == ce[k][1]) id1 = k;
      if (b == ce[k][0] && a == ce[k][1]) {
        id1 = k;
        dir1 = 1;
      }
    }
    if (id1 < 0) {
      id1 = ce.length;
      ce.push([a, b]);
      ei.push(new Edge([a, b]));
    }
    a = faces[i + 2];
    b = faces[i];
    var id2 = -1,
      dir2 = 0;
    cel = ce.length;
    for (var k = 0; k < cel; k++) {
      if (a == ce[k][0] && b == ce[k][1]) id2 = k;
      if (b == ce[k][0] && a == ce[k][1]) {
        id2 = k;
        dir2 = 1;
      }
    }
    if (id2 < 0) {
      id2 = ce.length;
      ce.push([a, b]);
      ei.push(new Edge([a, b]));
    }
    fi.push(new Face(id0, id1, id2, dir0, dir1, dir2));
    vior[faces[i]].push([id0, id2]);
    vior[faces[i + 1]].push([id1, id0]);
    vior[faces[i + 2]].push([id2, id1]);
  }
  for (var i = 0; i < cp.length / 3; i++) {
    vi[i] = [];
    var e = vior[i][0][0],
      id = 0;
    if (ce[e][0] == i) id = 1;
    vi[i].push([e, id]);
    e = vior[i][0][1];
    if (ce[e][0] == i) id = 1;
    else id = 0;
    vi[i].push([e, id]);

    for (var j = 1; j < vior[i].length - 1; j++) {
      var k = 1;
      while (e != vior[i][k][0]) k++;
      e = vior[i][k][1];
      if (ce[e][0] == i) id = 1;
      else id = 0;
      vi[i].push([e, id]);
    }
  }

  cpl3 = cp.length;
  cpl = lastP = vil = cpl3 / 3;
  cel2 = 2 * ce.length;
  for (var i = 0; i < cpl3; i++) p[i] = cp[i];

  // subdivisions
  for (var it = 0; it < n; it++) {
    ei0 = ei;
    fi0 = fi;
    var vil0 = vi.length;
    ei = [];
    fi = [];
    for (var i = 0; i < ei0.length; i++) ei0[i].subdiv();
    for (var i = 0; i < vil0; i++)
      for (var j = 0; j < vi[i].length; j++)
        vi[i][j][0] = ei0[vi[i][j][0]].E00 + 1 - vi[i][j][1];
    for (var i = 0; i < fi0.length; i++) fi0[i].subdiv();

    vil = vi.length;
    for (var i = 0; i < vil; i++) {
      var sx = (sy = sz = 0),
        lv = vi[i].length;
      for (var k = 0; k < lv; k++) {
        var j = 3 * ei[vi[i][k][0]].PS[vi[i][k][1]];
        sx += p[j++];
        sy += p[j++];
        sz += p[j++];
      }
      var j = 3 * i;
      p1[j] = an[lv] * p[j] + (sx * (1 - an[lv])) / lv;
      j++;
      p1[j] = an[lv] * p[j] + (sy * (1 - an[lv])) / lv;
      j++;
      p1[j] = an[lv] * p[j] + (sz * (1 - an[lv])) / lv;
    }
    for (var i = 0; i < 3 * vil; i++) p[i] = p1[i];
  }

  for (var i = 0; i < vil; i++) {
    var sx = (sy = sz = 0),
      lv = vi[i].length;
    var x1 = (x2 = y1 = y2 = z1 = z2 = 0);
    for (var k = 0; k < lv; k++) {
      var j = 3 * ei[vi[i][k][0]].PS[vi[i][k][1]];
      x1 += tauc[lv][k] * p[j];
      x2 += taus[lv][k] * p[j];
      sx += p[j++];
      y1 += tauc[lv][k] * p[j];
      y2 += taus[lv][k] * p[j];
      sy += p[j++];
      z1 += tauc[lv][k] * p[j];
      z2 += taus[lv][k] * p[j];
      sz += p[j++];
    }
    var x3 = y1 * z2 - y2 * z1,
      y3 = x2 * z1 - x1 * z2,
      z3 = x1 * y2 - x2 * y1;
    var norm3 = Math.sqrt(x3 * x3 + y3 * y3 + z3 * z3);
    var j = 3 * i;
    norm[j] = x3 / norm3;
    p1[j] = bn[lv] * p[j] + (sx * (1 - bn[lv])) / lv;
    j++;
    norm[j] = y3 / norm3;
    p1[j] = bn[lv] * p[j] + (sy * (1 - bn[lv])) / lv;
    j++;
    norm[j] = z3 / norm3;
    p1[j] = bn[lv] * p[j] + (sz * (1 - bn[lv])) / lv;
  }
}
