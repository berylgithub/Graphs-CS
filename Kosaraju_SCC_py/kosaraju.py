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

def kosaraju_reverse_DFS(reversed_graph, stack, visited, kos_vector, kos_track, scc, log=True):
    if log :
        print("stack = ",stack, "track = ",visited, "kos_vector=",kos_vector, "kos_track=",kos_track, "scc=",scc)
    #check if stack is empty
    if not stack:   
        #if the the kosaraju vector is not empty, visit the next node
        if kos_vector:
            for node in kos_vector:
                if node not in visited:
                    stack += [node]
                    visited += [node]
                    kos_track += [node]
                    kos_vector.remove(node)
                    break
            kosaraju_reverse_DFS(reversed_graph, stack, visited, kos_vector, kos_track, scc, log)
        #if kosaraju vector is empty
        elif not kos_vector:
            if log:
                print("reversed graph DFS finished")
                print("Strongly Connected Components = ", scc)
            
    else:
        #get stack top
        current = stack[-1]
        #traverse stack top's child
        if current in reversed_graph:
            for child in reversed_graph[current]:
                if child not in visited:
                    stack += [child]
                    visited += [child]
                    kos_track += [child]
                    kos_vector.remove(child)
                    break
            
        #if the stack's top doesnt change, means it is backtrack time, means append kos_track to scc, then empty kos_track
        if current == stack[-1]:
            #check if kos_track is empty, if yes, do nothing, else append it to scc list
            if kos_track:
                scc.append(kos_track)
                kos_track = []
            stack = stack[0:-1]
        kosaraju_reverse_DFS(reversed_graph, stack, visited, kos_vector, kos_track, scc, log)
    


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
    
    #traverse (again?...) the reversed graph to get the strongly connected components, start node by referring to kosaraju vector
    kos_vector = v_kosaraju_final
    root = kos_vector[0]
    stack = [root]
    visited = [root]
    kos_track = [root]
    kos_vector.remove(root)
    scc = []
    
    #start of DFS
    if root in reversed_graph:
        for child in reversed_graph[root]:
            if child not in visited:
                stack += [child]
                visited += [child]
                kos_track += [child]
                kos_vector.remove(child)
                break
    kosaraju_reverse_DFS(reversed_graph, stack, visited, kos_vector, kos_track, scc, log)
    
    
if __name__ == "__main__":
    print("Example 1 : ")
    graph = {0:[2,3], 1:[0], 2:[1], 3:[4], 4:[]}
    kosaraju_helper(graph, 0)
    
    print("\nExample 2 :")
    graph = {"A":["B"], "B":["C","D"], "C":["A"], "D":["E"],
             "E":["F"], "F":["D"], "G":["F","H"], "H":["I"],
             "I":["J"], "J":["G","K"], "K":[]}
    kosaraju_helper(graph, "A")
    
    print("\nExample 3 :")
    graph = {0:[1], 1:[2], 2:[3,4], 3:[0], 4:[5], 5:[6], 6:[4], 7:[6,8], 8:[]}
    kosaraju_helper(graph, 0)
    

    