def eraseOverlapIntervals(intervals):
    intervals = sorted(intervals, key= lambda x: x[1])
    count=1
    prev = intervals[0]
    for i in range(1, intervals.__len__()):
        if prev[1] <=intervals[i][0]:
            count= count+1
            prev = intervals[i]
    return intervals.__len__() - count








if __name__ == "__main__":
    print(eraseOverlapIntervals([[-52,31],[-73,-26],[82,97],[-65,-11],[-62,-49],[95,99],[58,95],[-31,49],[66,98],[-63,2],[30,47],[-40,-26]]))

        