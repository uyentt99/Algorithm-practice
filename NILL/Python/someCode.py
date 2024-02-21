# Remove repetition in labels by turning it into a set.
unique_labels = set(labels)
#or
unique_labels = np.unique(labels)
#
a = [i for i in range(10)]