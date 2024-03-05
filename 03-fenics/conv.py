import meshio

mesh = meshio.read('thor.msh')
mesh.write('thor.xml')