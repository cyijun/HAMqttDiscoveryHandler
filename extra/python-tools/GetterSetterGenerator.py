import linecache


className = 'HAMqttDiscoveryFan'
lineRange = [39, 46]

needGetter = False
needSetter = True
needConstruct = False


def get_line_context(file_path, line_number):
    return linecache.getline(file_path, line_number).strip()


fp = './'+className+'.h'


paramList = []
for line in range(lineRange[0], lineRange[1]):
    lineStr = get_line_context(fp, line)
    paramList.append(lineStr[lineStr.find(' '):lineStr.find(';')])

jsonKeyList = []
for param in paramList:
    for char in param:
        if str(char).isupper():
            key = param.replace(str(char), '_'+str(char), 1)
            key = key.upper()
            jsonKeyList.append(key)

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
