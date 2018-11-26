# -*- coding: utf-8 -*-
"""
Created on Mon Nov 26 17:18:30 2018

@author: YorozuyaSaint
"""

"""
Topological sort
"""


def topsort(graph, stack, visited, vis_topsort, log=True):
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
                    break
            topsort(graph, stack, visited, vis_topsort, log)
        #if all of the graph's node has been visited, just print it
        elif len(visited)==len(graph):
            vis_topsort = vis_topsort[::-1]
            if log:
                print("topological sort finished")
                print("track = ",visited)
                print("topological sort track = ", vis_topsort)
            
    else:
        #get stack top
        current = stack[-1]
        #traverse stack top's child
        for child in graph[current]:
            if child not in visited:
                stack += [child]
                visited += [child]
                break
            
        #if the stack's top doesnt change, time for backtrack !! (also add the node to topsort list)
        if current == stack[-1]:
            vis_topsort += [stack[-1]]
            stack = stack[0:-1]
        topsort(graph, stack, visited, vis_topsort, log)
    
    return vis_topsort[::-1]

                
        
    
def topsort_helper(graph, root, log=True):
    if log:
        print("start of topological sort")
    #init stack
    stack = [root]
    #init visited
    visited = [root]
    #init topsort list
    vis_topsort = []

    #start of DFS
    for child in graph[root]:
        if child not in visited:
            stack += [child]
            visited += [child]
            break
    return topsort(graph, stack, visited, vis_topsort, log)
            
            
if __name__ == "__main__":
    #example 1 :
    #graph representation using dictionary where key=observed node, values=list of child nodes
    graph={0:[], 1:[], 2:[3], 3:[1], 4:[0,1], 5:[0,2]}
    #start froma arbitrary root
    v_topsort = topsort_helper(graph, 4)
    print("\nexample 1, topological sort result = ",v_topsort,"\n")
    
    #example 2 :
    graph={1:[2,3], 2:[3,4], 3:[4,5], 4:[], 5:[]}
    v_topsort = topsort_helper(graph, 1, log=False)
    print("\nexample 2, topological sort result = ",v_topsort,"\n")
    
    #example 3 :
    graph={0:[1,3], 1:[2,3], 2:[3,4,5], 3:[4,5], 4:[5], 5:[]}
    v_topsort = topsort_helper(graph, 5, log=False)
    print("\nexample 3, topological sort result = ",v_topsort,"\n")
    
    #example 4 :
    graph={"A":["B","C"], "B":["D"], "C":["D"], "D":["E"], "E":[]}
    v_topsort = topsort_helper(graph, "A")
    print("\nexample 3, topological sort result = ",v_topsort,"\n")
    
    #example 5 :
    graph={"A":["B","F"], "B":["H"], "C":[], 
           "D":["C","I","E","H"], "E":["I"], "F":[], 
           "G":["A","B","C"], "H":[], "I":["C"], 
           "J":["E"]}
    v_topsort = topsort_helper(graph, "A", log=False)
    print("\nexample 3, topological sort result = ",v_topsort,"\n")
    