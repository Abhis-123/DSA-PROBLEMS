#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    
    int  get_param(vector<vector<int>>& grid, int i, int j, vector<vector<bool>>& visited){
        int n = grid.size(), m = grid[0].size();
        if(i<0||j<0|| i>=n || j>=m || grid[i][j]==0) return 1;

        if(visited[i][j]==true) return 0;
        visited[i][j] = true;
        return  get_param(grid,i,j+1,visited) + get_param(grid,i+1,j,visited)+get_param(grid,i,j-1,visited)+ get_param(grid,i-1,j,visited);  
    }

    int get_area_of_island(vector<vector<int>>& grid, int i, int j){
        int n= grid.size(), m = grid[0].size();
        if(i<0||j<0|| i>=n || j>=m || grid[i][j]==0) return 0;
        grid[i][j] = 0;
        return 1 + get_area_of_island(grid, i+1, j)+ get_area_of_island(grid,i, j+1)+ get_area_of_island(grid,i,j-1)+ get_area_of_island(grid,i-1,j); 
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int max_area = 0;
        int n = grid.size(), m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                    if(grid[i][j]==1){
                        int area = get_area_of_island(grid, i, j);
                        if(area> max_area){
                            max_area = area;
                        }
                    }
            }
        }
        return max_area;
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int total_land_cells = 0;
        for(int i = 0; i < n; i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    total_land_cells += grid[i][j];
                }
            }
        }
        int open_cells =0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || j == 0 || i==n-1|| j==m-1){
                    open_cells += get_area_of_island(grid,i, j);
                }
            }
        }
        return total_land_cells - open_cells;
    }

    bool is_land_connected_to_border(vector<vector<int>>& grid, int i, int j){
        int n = grid.size(), m = grid[0].size();
        if(i<0 || j<0|| i>=n || j>=m) return false;
        if(grid[i][j]==1) return true;
        grid[i][j] =1;
        bool res = true;
        res = is_land_connected_to_border(grid,i-1,j) && res;
        res = is_land_connected_to_border(grid,i+1,j) && res;
        res = is_land_connected_to_border(grid,i,j+1) && res;
        res = is_land_connected_to_border(grid,i,j-1) && res;
        return res;
        }

    int min_distance_to_land(vector<vector<int>>& grid, vector<vector<int>>& min_dist, int i, int j) {
        int n = grid.size(), m = grid[0].size();
        if(i<0||j<0|| i>=n || j>=m)  return 10000000;
        if(min_dist[i][j]!=-1) return  min_dist[i][j];
        if(grid[i][j]==0){
            min_dist[i][j]=0;
            return 0;
        }

        int min_distance = 10000000;
        int temp = min_distance_to_land(grid, min_dist, i-1, j);
        if(temp<min_distance) min_distance = temp;
        temp = min_distance_to_land(grid, min_dist, i+1, j);
        if(temp<min_distance) min_distance = temp;
        temp = min_distance_to_land(grid, min_dist, i, j+1);
        if(temp<min_distance) min_distance = temp;
        temp = min_distance_to_land(grid, min_dist, i, j-1);
        if(temp<min_distance) min_distance = temp;
        min_dist[i][j] = temp;
        return temp;

    }
};