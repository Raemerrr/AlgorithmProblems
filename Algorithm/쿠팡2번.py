
import datetime

def solution(n, customers):
    answer = 0
    #기기 초기화
    initStr = '01/01 00:00:00'
    initData = datetime.datetime.strptime(initStr,'%m/%d %H:%M:%S')
    machineCnt = {}
    machineDic = {}
    addDateTime = datetime.timedelta(seconds=1)
    for i in range(n):
        machineDic[i] = initData + addDateTime
        machineCnt[i] = 0
    #고객 데이터
    customersData = {}
    for customerID in range(len(customers)) :
        customersData[customerID] = customers[customerID].split()

    for i in range(len(customers)) :
        startDateTimeStr = customersData[i][0] + ' ' + customersData[i][1]
        startDateTime = datetime.datetime.strptime(startDateTimeStr,'%m/%d %H:%M:%S')
        addDateTime = datetime.timedelta(minutes=int(customersData[i][2]))
        flag = True
        machineList = []
        for m in range(n):
            if machineDic[m] <= startDateTime:
                machineList.append(m)
        if len(machineList) > 0 :
            maxKey = 0
            t = datetime.timedelta(days=0, seconds=0, microseconds=0, milliseconds=0, minutes=0, hours=0, weeks=0)
            for k in machineList:
                if startDateTime - machineDic[k] > t:
                    t = startDateTime - machineDic[k]
                    maxKey = k
            machineCnt[maxKey] += 1
            machineDic[maxKey] = startDateTime + addDateTime
            flag = False
            
        if flag :
            compStr = '12/31 23:59:59'
            compTime = datetime.datetime.strptime(compStr,'%m/%d %H:%M:%S')
            minKey = 0
            for k in machineDic.keys():
                if machineDic[k] < compTime:
                    compTime = machineDic[k]
                    minKey = k
            machineCnt[minKey] += 1
            machineDic[minKey] += addDateTime
            
    answer = machineCnt[max(machineCnt.keys(), key=(lambda k : machineCnt[k]))]
    return answer

if __name__ == "__main__":
     
    # StrDateTime= '02/06 18:29:36 30'
    # DateTime= datetime.datetime.strptime(StrDateTime,'%m/%d %H:%M:%S')
    # print(type(DateTime))
    # print(DateTime)

    #c = ["10/01 23:20:25 30", "10/01 23:25:50 26", "10/01 23:31:00 05", "10/01 23:33:17 24", "10/01 23:50:25 13", "10/01 23:55:45 20", "10/01 23:59:39 03", "10/02 00:10:00 10"]
    #print(solution(3,c))

    c= ["02/28 23:59:00 03","03/01 00:00:00 02", "03/01 00:05:00 01"]
    print(solution(2,c))