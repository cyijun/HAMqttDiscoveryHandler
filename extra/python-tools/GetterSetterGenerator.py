import linecache


className = 'HAMqttDiscoveryClimate'
lineRange = [38, 46]

needGetter = False
needSetter = False
needConstruct = True


def get_line_context(file_path, line_number):
    return linecache.getline(file_path, line_number).strip()


fp = './'+className+'.h'


paramList = []
for line in range(lineRange[0], lineRange[1]+1):
    lineStr = get_line_context(fp, line)
    if(lineStr.find(';')>=0):
        paramList.append(lineStr[lineStr.find(' '):lineStr.find(';')])

jsonKeyList = []
for param in paramList:
    key=param
    for char in key:
        if str(char).isupper():
            cutindex = key.find(str(char))
            key = key[:cutindex]+'_'+str(char).lower()+key[cutindex+1:]
    key = key.upper()
    jsonKeyList.append(key)
print(jsonKeyList)

getterHeaderList = []
setterHeaderList = []
getterFunctionList = []
setterFunctionList = []
rawList = []
for param in paramList:
    cut = param[2:]
    raw = cut.replace(str(cut[0]), str(cut[0]).upper(), 1)
    rawList.append(raw)


if needGetter:
    for raw in rawList:
        getterHeaderList.append('String get'+raw+'();')
    print('//******** Getters ********')
    for getterHeader in getterHeaderList:
        print(getterHeader)
    print()

    for i in range(0, rawList.__len__()):
        getterFunctionList.append(
            'String ' + className+'::get'+rawList[i]+'()\n{\n\treturn '+paramList[i]+';\n}')
    for getterFunction in getterFunctionList:
        print(getterFunction)
    print()

if needSetter:
    for i in range(0, rawList.__len__()):
        setterHeaderList.append(
            'void set'+rawList[i]+'(String '+paramList[i][2:]+');')
    print('//******** Setters ********')
    for setterHeader in setterHeaderList:
        print(setterHeader)
    print()

    for i in range(0, rawList.__len__()):
        setterFunctionList.append('void ' + className+'::set' +
                                  rawList[i]+'(String '+paramList[i][2:]+')\n{\n\t'+paramList[i]+'='+paramList[i][2:]+';\n}')
    for setterFunction in setterFunctionList:
        print(setterFunction)
    print()

if needConstruct:
    for i in range(0, rawList.__len__()):
        print('if(!'+paramList[i]+'.isEmpty()){\n\tdoc['+jsonKeyList[i]+']='+paramList[i]+';\n\tdoc['+jsonKeyList[i].replace('TEMPLATE',"TOPIC")+']=_ctrlTopic;\n}')
