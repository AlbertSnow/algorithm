package map.com.albert;

// 迪克斯特
public class Dijkstra  {

    static final int V = 9;

    int minDistance(int dist[], boolean shortPathSet[]) {
        int min = Integer.MAX_VALUE;
        int minIndex = -1;

        for (int v=0; v<V; v++) {
            if (shortPathSet[v] == false && dist[v] <= min) {
                min = dist[v];
                minIndex = v;
            }
        }

        return minIndex;
    }

    void printPath (int dist[]) {
        System.out.println ("The distance of vertex from source");

        for (int i = 0; i < V; i++) 
            System.out.println(i + " \t\t " + dist[i]); 
    }
    

    void dijkstra(int graph[][], int src) {
        int[] dist = new int[V];

        boolean[] shortestPathSet = new boolean[V];

        for (int i=0; i<V; i++) {
            dist[i] = Integer.MAX_VALUE;
            shortestPathSet[i] = false;
        }

        dist[src] = 0;

        for (int count = 0; count < V-1; count++) {
            int minIndex = minDistance(dist, shortestPathSet);
            shortestPathSet[minIndex] = true;
            
            for (int adjacent= 0; adjacent<V; adjacent++) {
                if(shortestPathSet[adjacent] == false &&
                    graph[minIndex][adjacent] != 0 && 
                    dist[minIndex] != Integer.MAX_VALUE &&
                    dist[adjacent] > dist[minIndex] + graph[minIndex][adjacent]) {
                        dist[adjacent] = dist[minIndex] + graph[minIndex][adjacent];
                    }
            }
        }

        printPath(dist);
    }

    public static void main(String[] args) {
        int graph[][] = new int[][] { { 0, 4, 0, 0, 0, 0, 0, 8, 0 }, 
        { 4, 0, 8, 0, 0, 0, 0, 11, 0 }, 
        { 0, 8, 0, 7, 0, 4, 0, 0, 2 }, 
        { 0, 0, 7, 0, 9, 14, 0, 0, 0 }, 
        { 0, 0, 0, 9, 0, 10, 0, 0, 0 }, 
        { 0, 0, 4, 14, 10, 0, 2, 0, 0 }, 
        { 0, 0, 0, 0, 0, 2, 0, 1, 6 }, 
        { 8, 11, 0, 0, 0, 0, 1, 0, 7 }, 
        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } }; 

        Dijkstra dijkstra = new Dijkstra();
        dijkstra.dijkstra(graph, 0);
    }
 
}