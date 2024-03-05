#include <dolfin.h>
#include "Poisson.h"

using namespace dolfin;

class Source : public Expression
{
  void eval(Array<double> &values, const Array<double> &x) const
  {
    values[0] = x[0] * x[0] + x[1] * x[1] + x[2] * x[2];
  }
};

class DirichletCond : public Expression
{
  void eval(Array<double> &values, const Array<double> &x) const
  {
    values[0] = cos(sqrt(x[0] * x[0] + x[1] * x[1]) * 100) + cos(x[2] * 100) + 0.25 * cos(x[0] * 200) + 0.25 * cos(x[1] * 200);
  }
};

class DirichletBoundary : public SubDomain
{
  bool inside(const Array<double> &x, bool on_boundary) const
  {
    double r_outer = 0.06, r_center = 0.15;
    double r = sqrt(x[0] * x[0] + x[1] * x[1]);
    double h2 = r_outer * r_outer - (r - r_center) * (r - r_center);
    if (h2 < 0) return false;
    return fabs(x[2] * x[2] - h2) < 1e-2;
  }
};

int main()
{
  long unsigned size = 8;
  // auto mesh = std::make_shared<Mesh>(UnitCubeMesh::create({size, size, size}, CellType::Type::tetrahedron));

  auto mesh =  std::make_shared<Mesh>(Mesh("../thor.xml"));

  auto V = std::make_shared<Poisson::FunctionSpace>(mesh);

  auto u0 = std::make_shared<DirichletCond>();
  auto boundary = std::make_shared<DirichletBoundary>();
  DirichletBC bc(V, u0, boundary);

  Poisson::BilinearForm a(V, V);
  Poisson::LinearForm L(V);
  auto f = std::make_shared<Source>();
  L.f = f;

  Function u(V);
  solve(a == L, u, bc);

  // Save solution in VTK format
  File file("poisson.pvd");
  file << u;

  return 0;
}
