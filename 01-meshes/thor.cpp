#include <set>
#include <gmsh.h>

int main(int argc, char **argv) {

    gmsh::initialize();

    gmsh::model::add("thor");

    double inner_radius = .1;
    double outer_radius = .2;
    double ring_radius = (outer_radius - inner_radius) / 2;
    double h = .01;

    double lc = 5e-3;
    gmsh::model::geo::addPoint(0, 0, 0, lc, 1);
    gmsh::model::geo::addPoint(inner_radius, 0, 0, lc, 2);
    gmsh::model::geo::addPoint(-inner_radius, 0, 0, lc, 3);

    gmsh::model::geo::addCircleArc(2, 1, 3, 1);
    gmsh::model::geo::addCircleArc(3, 1, 2, 2);

    gmsh::model::geo::addPoint(outer_radius, 0, 0, lc, 4);
    gmsh::model::geo::addPoint(-outer_radius, 0, 0, lc, 5);

    gmsh::model::geo::addCircleArc(4, 1, 5, 3);
    gmsh::model::geo::addCircleArc(5, 1, 4, 4);

    gmsh::model::geo::addPoint((inner_radius + outer_radius) / 2, 0, 0, lc, 6);
    gmsh::model::geo::addPoint(-(inner_radius + outer_radius) / 2, 0, 0, lc, 7);

    gmsh::model::geo::addCircleArc(2, 6, 4, 5, 0, 1, 0);
    gmsh::model::geo::addCircleArc(3, 7, 5, 6, 0, -1, 0);
    gmsh::model::geo::addCircleArc(2, 6, 4, 7, 0, -1, 0);
    gmsh::model::geo::addCircleArc(3, 7, 5, 8, 0, 1, 0);

    gmsh::model::geo::addCurveLoop({1, -5, -3, 6}, 1);
    gmsh::model::geo::addCurveLoop({2, 5, -4, -6}, 2);
    gmsh::model::geo::addCurveLoop({1, -7, -3, 8}, 3);
    gmsh::model::geo::addCurveLoop({2, 7, -4, -8}, 4);

    gmsh::model::geo::addSurfaceFilling({1}, 1);
    gmsh::model::geo::addSurfaceFilling({2}, 2);
    gmsh::model::geo::addSurfaceFilling({3}, 3);
    gmsh::model::geo::addSurfaceFilling({4}, 4);



    // gmsh::model::geo::addPoint(inner_radius - h, 0, 0, lc, 8);
    // gmsh::model::geo::addPoint(-inner_radius + h, 0, 0, lc, 9);

    // gmsh::model::geo::addCircleArc(8, 1, 9, 9);
    // gmsh::model::geo::addCircleArc(9, 1, 8, 10);

    // gmsh::model::geo::addPoint(outer_radius + h, 0, 0, lc, 10);
    // gmsh::model::geo::addPoint(-outer_radius - h, 0, 0, lc, 11);

    // gmsh::model::geo::addCircleArc(10, 1, 11, 11);
    // gmsh::model::geo::addCircleArc(11, 1, 10, 12);

    // gmsh::model::geo::addCircleArc(8, 6, 10, 13, 0, 1, 0);
    // gmsh::model::geo::addCircleArc(9, 7, 11, 14, 0, -1, 0);
    // gmsh::model::geo::addCircleArc(8, 6, 10, 15, 0, -1, 0);
    // gmsh::model::geo::addCircleArc(9, 7, 11, 16, 0, 1, 0);

    // gmsh::model::geo::addCurveLoop({9, -13, -11, 14}, 5);
    // gmsh::model::geo::addCurveLoop({10, 13, -12, -14}, 6);
    // gmsh::model::geo::addCurveLoop({9, -15, -11, 16}, 7);
    // gmsh::model::geo::addCurveLoop({10, 15, -12, -16}, 8);

    // gmsh::model::geo::addSurfaceFilling({5}, 5);
    // gmsh::model::geo::addSurfaceFilling({6}, 6);
    // gmsh::model::geo::addSurfaceFilling({7}, 7);
    // gmsh::model::geo::addSurfaceFilling({8}, 8);

    // gmsh::model::geo::addSurfaceLoop({1, 2, 3, 4, 5, 6, 7, 8}, 1);
    // gmsh::model::geo::addVolume({1});

    gmsh::model::geo::synchronize();

    gmsh::model::mesh::generate(3);

    gmsh::write("thor.msh");

    std::set<std::string> args(argv, argv + argc);
    if(!args.count("-nopopup")) gmsh::fltk::run();

    gmsh::finalize();

    return 0;
}

