import matplotlib.pyplot as plt 
fig = plt.figure(figsize=(6, 4))
#for axes ------ hệ tọa độ
ax = plt.axes(xlim=(0, 2), ylim=(-2, 2))
# for subplot
ax = fig.add_subplot(1, 1, 1)
#or
plt.subplot(111)
# Create colors for the clusters.
colors = plt.cm.Spectral(np.linspace(0, 1, len(unique_labels)))
colors
#-------plt or ax is ok-------
    # Remove the x ticks, y ticks, x and y axis #plt.axis('off')
    plt.xticks([])
    plt.yticks([])
    # vẽ điểm 
    plt.scatter(x,y)
    # vẽ đường
    plt.plot(x,y)
    # xlable, ylable
    #label marker
    ax.plot([], [], '^', c='b', label="Target".format('^'))
    #
    plt.ylabel()
    plt.xlabel()
#show
plt.show()