
mkdir build
cd build
cmake ..
cmake --build .
cd ..
pyenv local env4ml
python setup.py bdist_wheel

pip install dist/*.whl
# pip install dist/*.whl --force-reinstall

python

>>> import hideseek
>>> g = hideseek.Game(10, 1) # or (10, 0), 0 for not displaying on the terminal
>>> g.RunOneEvent(3, 1) # `RunOneEvent(event, iter)` event(movement) and iter(iteration): integers
>>> g.sceneHider
>>> g.sceneSeeker
>>> g.gameOver
>>> g.isDay
