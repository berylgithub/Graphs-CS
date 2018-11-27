# -*- coding: utf-8 -*-
"""
Created on Mon Nov 26 21:18:35 2018

@author: YorozuyaSaint
"""

"""
Kosaraju Algorithm - Strongly Connected Components of Graph
"""
from collections import OrderedDict


def kosaraju_DFS(graph, stack, visited, v_kosaraju, log=True):
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
                    v_kosaraju += [node]
                    break
            kosaraju_DFS(graph, stack, visited, v_kosaraju, log)
        #if all of the graph's node has been visited, just print it
        elif len(visited)==len(graph):
            if log:
                print("DFS finished")
                print("track = ",visited)
            
    else:
        #get stack top
        current = stack[-1]
        #traverse stack top's child
        for child in graph[current]:
            if child not in visited:
                stack += [child]
                visited += [child]
                v_kosaraju += [child]
                break
            
        #if the stack's top doesnt change, time for backtrack !! (also add current to kosaraju vector)
        if current == stack[-1]:
            v_kosaraju += [current]
            stack = stack[0:-1]
        kosaraju_DFS(graph, stack, visited, v_kosaraju, log)
    
    return v_kosaraju

def kosaraju_reverse_DFS(graph, stack, visited, scc, log=True):
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
            kosaraju_reverse_DFS(graph, stack, visited, scc, log)
        #if all of the graph's node has been visited, just print it
        elif len(visited)==len(graph):
            if log:
                print("DFS finished")
                print("track = ",visited)
            
    else:
        #get stack top
        current = stack[-1]
        #traverse stack top's child
        for child in graph[current]:
            if child not in visited:
                stack += [child]
                visited += [child]
                break
            
        #if the stack's top doesnt change, add the current route to SCC list, then pop all of the routes from kosaraju vector
        if current == stack[-1]:
            scc.append(visited)
            stack = stack[0:-1]
        kosaraju_reverse_DFS(graph, stack, visited, scc, log)
    
    return scc


def kosaraju_helper(graph, root, log=True):
    #init stack
    stack = [root]
    #init visited
    visited = [root]
    #init kosaraju vector
    v_kosaraju = [root]

    #start of DFS
    for child in graph[root]:
        if child not in visited:
            stack += [child]
            visited += [child]
            v_kosaraju += [child]
            break
    #get the kosaraju vector using dfs
    print("DFS-kosaraju")
    v_kosaraju_final = kosaraju_DFS(graph, stack, visited, v_kosaraju, log)
    v_kosaraju_final = list(OrderedDict.fromkeys(reversed(v_kosaraju_final)))
    print("kosaraju vector = ", v_kosaraju_final)
    
    #reverse graph
    child_set = set([child for parent in graph for child in graph[parent]])
    reversed_graph= {}
    for child in child_set:
        reversed_graph[child]=[]
    for parent in graph:
        for child in child_set:
            if child in graph[parent]:
                reversed_graph[child] += [parent]
    print("reversed graph = ",reversed_graph)
    
    #traverse (again?...) the reversed graph to get the strongly connected components
    stack = [reversed_graph[0]]
    visited = [reversed_graph[0]]
    scc = []
    
    #start of DFS
    for child in graph[root]:
        if child not in visited:
            stack += [child]
            visited += [child]
            break
    #get the kosaraju vector using dfs
    #kosaraju_DFS(graph, stack, visited, v_kosaraju, log)
    
    
if __name__ == "__main__":
    graph = {0:[2,3], 1:[0], 2:[1], 3:[4], 4:[]}
    kosaraju_helper(graph, 0)
    


    

    