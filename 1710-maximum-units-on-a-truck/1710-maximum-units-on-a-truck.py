class Solution:
    def maximumUnits(self, boxTypes: list[list[int]], truckSize: int) -> int:
        boxTypes.sort(key=lambda x: x[1], reverse=True)
        maxUnits = 0
        for box in boxTypes:
            numBoxes = box[0]
            unitsPerBox = box[1]
            boxesToTake = min(numBoxes, truckSize)
            maxUnits += boxesToTake * unitsPerBox
            truckSize -= boxesToTake
            if truckSize == 0:
                break
        return maxUnits