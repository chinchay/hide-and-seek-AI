// see example at
// https://www.matecdev.com/posts/cpp-call-from-python.html#:~:text=There%20are%20basically%20two%20ways,%2Dlevel%20C%2Dstyle%20solution.

#include <pybind11/pybind11.h>

//https://pybind11.readthedocs.io/en/stable/advanced/cast/stl.html
#include <pybind11/stl.h> // allow to convert vector (C++) to list (Python)

#include "game.h"

namespace py = pybind11;
constexpr auto byref = py::return_value_policy::reference_internal;

PYBIND11_MODULE(hideseek, m) {
    m.doc() = "optional module docstring";

    py::class_<Game>(m, "Game")
    .def(py::init<int, int>())  
    .def("RunOneEvent", &Game::RunOneEvent, py::call_guard<py::gil_scoped_release>())
    .def_readonly("sceneHider",  &Game::sceneHider, byref)
    .def_readonly("sceneSeeker", &Game::sceneSeeker, byref)
    .def_readonly("gameOver",    &Game::gameOver, byref)
    .def_readonly("isDay",       &Game::isDay, byref)
    ;
}