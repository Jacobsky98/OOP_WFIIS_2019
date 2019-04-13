import os
import tarfile

tarName = os.path.basename(os.getcwd())
tarName = tarName + ".tar.gz"
print(tarName)

listaCPP = list()
listaH = list()
for file in os.listdir(os.getcwd()):
    if file.endswith(".cpp"):
        listaCPP.append(file)
    if file.endswith(".h"):
        listaH.append(file)

tar = tarfile.open(tarName, "w:gz")
for name in listaCPP:
    tar.add(name)
for name in listaH:
    tar.add(name)
tar.add('makefile')
tar.close()