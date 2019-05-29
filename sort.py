import sys

def returnLabels(data):
        """
        Returns the labels in a list by the order of their appearance in the file.
        """
        labels = []
        splittedData = data.split()
        for word in splittedData:
                if ":" in word and "L" in word:
                        labels.append(word)
        return labels

def returnIndexes(labels):
        """
        Returns the indexes of the labels in a list by the order of the labels list.
        """
        indexes = []
        for label in labels:
                label = label.replace("L","").replace(":","")
                try:
                        label = int(label)
                except ValueError:
                        continue        
                indexes.append(label)
        return indexes

def sortedData(labels, indexes, data):
        """
        Sort the labels in ascending order, swaps the labels appearances.
        """
        for index1 in range(len(indexes)):
                for index2 in range(index1+1,len(indexes)):
                        if indexes[index1] > indexes[index2]:
                                smaller = labels[index2].replace(":","")
                                bigger = labels[index1].replace(":","")
                                indexes[index1], indexes[index2] = indexes[index2], indexes[index1]
                                labels[index1], labels[index2] = labels[index2], labels[index1]
                                data = data.replace(bigger, "temp" + bigger)
                                data = data.replace(smaller, bigger)
                                data = data.replace("temp" + bigger, smaller)
        return data

def main():
        with open(sys.argv[1],"r") as f:
                data = f.read()
        labels = returnLabels(data)
        indexes = returnIndexes(labels)
        with open(sys.argv[1]+"AfterScript.txt","w") as f:
                f.write(sortedData(labels, indexes, data)) # Writes the sorted data into a file.

if __name__ == "__main__":
        main()