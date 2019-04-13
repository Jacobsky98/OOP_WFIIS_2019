plikMain = 'main.cpp'
outputFile = 'output.txt'



def compareList(list1, list2):
    if(list1 == list2):
        return 1
    else:
        return 0

try:
    with open(plikMain) as f:
        output = f.read()
    f.close()
except:
    print("Brak pliku " + plikMain)
    quit()

try:
    with open(outputFile) as f:
        goodOutput = f.read()
    f.close()
except:
    print("Brak pliku " + outputFile)
    quit()


kom = output.rfind('/*')
kom2 = output.rfind('\n')

#print(str(kom) + "   " + str(kom2) + " = " + str(kom2-kom))
output = output[kom:kom2]



outputCPP = []
while output.index('\n') < len(output)-1:
    output = output[(output.index('\n')+1):]   
    try:
        outputCPP.append(output[:output.index('\n')])
    except:
        break

outputCPPGood = []
while goodOutput.index('\n') < len(goodOutput)-1:
    goodOutput = goodOutput[(goodOutput.index('\n')+1):]   
    try:
        outputCPPGood.append(goodOutput[:goodOutput.index('\n')])
    except:
        break

n = min(len(outputCPP), len(outputCPPGood))
for i in range(0, n):
    if(compareList(outputCPP[i], outputCPPGood[i]) == 1):
        print('OK \t' + outputCPP[i])
    else:
        print("ERROR " + outputCPP[i] + ' != ' + outputCPPGood[i])
