# -*- coding: utf-8 -*-
"""
Created on Wed Nov 28 10:04:40 2018

@author: YorozuyaSaint
"""

"""
Modified DFS to solve Aufa's GF puzzle problem
"""

def modified_DFS(graph, stack, visited, depth_vec, log=True):
    if log :
        print("stack = ",stack, "track = ",visited)
    #check if stack is empty
    if not stack:   
        #if there are unvisited nodes, do dfs
        if len(visited)<len(graph):
            for node in graph:
                if node not in visited:
                    stack += [node]
                    visited += [node]
                    depth_vec[node] = len(stack)
                    break
            modified_DFS(graph, stack, visited, depth_vec, log)
        #if all of the graph's node has been visited, just print it
        elif len(visited)==len(graph):
            if log:
                print("DFS finished")
                print("track = ",visited, "depth_vector{node:depth} = ",depth_vec)
            
    else:
        #get stack top
        current = stack[-1]
        #traverse stack top's child
        if current in graph:
            for child in graph[current]:
                if child not in visited:
                    stack += [child]
                    visited += [child]
                    depth_vec[child] = len(stack)
                    break
            
        #if the stack's top doesnt change, time for backtrack !!
        if current == stack[-1]:
            stack = stack[0:-1]
        modified_DFS(graph, stack, visited, depth_vec, log)
    return depth_vec

def modified_DFS_helper(graph, root, gfs, log=True):
    if log:
        print("start of DFS for Aufa's GFs")
    #init stack
    stack = [root]
    #init visited
    visited = [root]
    #init depth vector, which is {node:depth}
    depth_vec = {root:len(stack)}
    
    #start of DFS
    if root in graph:
        for child in graph[root]:
            if child not in visited:
                stack += [child]
                visited += [child]
                depth_vec[child] = len(stack)
                break
    depth_vec=modified_DFS(graph, stack, visited, depth_vec, log)
    #sort the nodes by the depth
    depth_sorted = sorted(depth_vec.items(), key=lambda x: x[1])
    gf_depth_node = [node for node in depth_sorted for gf in gfs if gf==node[0]]
    #get the closest GF !!
    return gf_depth_node[0][0]
    
            

if __name__ == "__main__":
    graph = {1:[2,3,4], 2:[5,6], 3:[], 4:[], 5:[], 6:[]}
    gfs = [5,6,3,4]
    closest_gf = modified_DFS_helper(graph, 1, gfs)
    print("Aufa's GF is located at node = ",closest_gf)