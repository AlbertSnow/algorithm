package map.com.albert;

import java.util.ArrayDeque;
import java.util.Queue;

public class MazeAlgorithm {

    private static final int M = 10;
    private static final int N = 10;

    private static final int goRow[] = {-1, 0, 0, 1};
    private static final int goCol[] = {0, -1, 1, 0};

    private static boolean isValid(int mat[][], boolean visited[][], 
        int row, int col) {
            return (row >= 0) && (row < M) &&
                    (col >= 0) && (col < N) &&
                    mat[row][col] == 1 &&
                    !visited[row][col];
    }

    //source [i, j] destination[x, y]
    private static void BFS(int mat[][], int i, int j, int x, int y) {
        boolean[][] visited = new boolean[M][N];

        Queue<Node> queue = new ArrayDeque<>();
        queue.add(new Node(i, j, 0));
        Node currentNode;

        int distance = Integer.MAX_VALUE;
        while (!queue.isEmpty()) {
            currentNode = queue.poll();

            if (currentNode.x == x && currentNode.y == y) {
                distance = currentNode.dist;
                break;
            }

            for (int a = 0; a < 4; a++) {
                int nextI = i + goRow[a] + currentNode.x;
                int nextJ = j + goCol[a] + currentNode.y;
                if (isValid(mat, visited, nextI, nextJ)) {
                    visited[nextI][nextJ]  = true;
                    queue.add(new Node(nextI, nextJ, currentNode.dist + 1));
                }
            }
        } //while

        if (distance != Integer.MAX_VALUE) {
            System.out.println("Find shortest path, distance is : " + distance);
        } else {
            System.out.println("Can't find shortest path");

        }

    }


    static class Node {
        int x,y,dist;

        Node(int x, int y, int dist) {
            this.x = x;
            this.y = y;
            this.dist = dist;
        }
    }


    public static void main(String[] args) {
		// input maze
		int[][] mat =
		{
			{ 1, 1, 1, 1, 1, 0, 0, 1, 1, 1 },
			{ 0, 1, 1, 1, 1, 1, 0, 1, 0, 1 },
			{ 0, 0, 1, 0, 1, 1, 1, 0, 0, 1 },
			{ 1, 0, 1, 1, 1, 0, 1, 1, 0, 1 },
			{ 0, 0, 0, 1, 0, 0, 0, 1, 0, 1 },
			{ 1, 0, 1, 1, 1, 0, 0, 1, 1, 0 },
			{ 0, 0, 0, 0, 1, 0, 0, 1, 0, 1 },
			{ 0, 1, 1, 1, 1, 1, 1, 1, 0, 0 },
			{ 1, 1, 1, 1, 1, 0, 0, 1, 1, 1 },
			{ 0, 0, 1, 0, 0, 1, 1, 0, 0, 1 },
		};

        BFS(mat, 0, 0, 7, 5);
    }

}
