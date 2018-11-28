# -*- coding: utf-8 -*-
"""
Created on Wed Nov 28 11:51:30 2018

@author: YorozuyaSaint
"""

"""
Modified BFS to solve highway roads puzzle (find the fastest path)
"""

def modified_BFS(graph, queue, visited, vec_track):
    print("queue=",queue,"track=",visited, "vec_track[[track], track_length]=",vec_track)
    #if queue is not empty
    if queue:
        current = queue[0]
        if current not in visited:
            visited+=[current]
        if current in graph:
            for node in graph[current]:
                #add to queue if has not been visited
                if node not in visited:
                    queue+=[node]
                    #if there is any list that has the same value with current node, add it to the tail, and also prev_tail_sum += new_edge_sum
                    for vec in vec_track:
                        if vec[0][-1]==current:
                            vec[1]+=graph[current][node]
                            vec[0]+=[node]
        #deque
        if queue:
            queue=queue[1:]

        modified_BFS(graph, queue, visited, vec_track)
    #queue is empty
    elif not queue :
        print("BFS finished")
        print("BFS track = ", visited)
    
    return vec_track
                    

    
    
def modified_BFS_helper(graph, root):
    queue=[root]
    visited=[root]
    vec_track = []
    if root in graph:
        for node in graph[root]:
            if node not in visited:
                queue+=[node]
    
    
    #dequeue the already visited node
    queue=queue[1:]
    for dest in queue:
        vec_track.append([[root, dest], graph[root][dest]])
    vec_track = modified_BFS(graph, queue, visited, vec_track)
    print("vec_track[[track], track_length]=",vec_track)
    #sort the vec_track by its track length
    vec_track.sort(key=lambda x: x[1])
    print("the shortest track is :",vec_track[0][0], "with track length (number of bypass used) = ",vec_track[0][1])
    return vec_track

if __name__ == "__main__":
    #weighted graph, which is {source:[{destination:weight,dest:weight,...}]}
    graph = {1:{3:1, 11:1, 20:2, 15:2, 30:3},
             3:{100:3}, 11:{100:1}, 20:{100:7}, 15:{100:8}, 30:{100:4}}
    modified_BFS_helper(graph, 1)
