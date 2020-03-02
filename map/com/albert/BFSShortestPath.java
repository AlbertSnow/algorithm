package map.com.albert;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Stack;

public class BFSShortestPath {

    public static class Graphic {
        public static final int[][] graphic = new int[][]{
            {1,2}, 
            {2, 5},
            {1, 3},
            {3, 4, 5},
            {5},
            {}
        };

        public int getVerticalCount() {
            return graphic.length;
        }

        public int[] getChilds(final int currentNode) {
            return graphic[currentNode];
        }
    }

    private final Graphic graphic;
    private boolean[] visited;
    private int[] lengthToStartNode;
    private int[] parentNodes;
    private final int startNode;

    public BFSShortestPath(final Graphic graphic, final int startPoint) {
        this.graphic = graphic;
        this.startNode = startPoint;
        if (startNode >= graphic.getVerticalCount()) {
            throw new IllegalArgumentException();
        }
        initData();
    }

    private void initData() {
        int currentNode = startNode;
        final int vCount = graphic.getVerticalCount();

        visited = new boolean[vCount];
        lengthToStartNode = new int[vCount];
        parentNodes = new int[vCount];

        for (int i = 0; i < vCount; i++) {
            visited[i] = false;
            lengthToStartNode[i] = -1;
            parentNodes[i] = -1;
        }

        final Queue<Integer> queue = new LinkedList<>();
        queue.add(currentNode);

        while (!queue.isEmpty()) {
            currentNode = queue.poll();

            final int[] childs = graphic.getChilds(currentNode);
            for (final int childIndex : childs) {
                if (visited[childIndex]) {
                    continue;
                }

                parentNodes[childIndex] = currentNode;
                visited[childIndex] = true;
                lengthToStartNode[childIndex] = lengthToStartNode[currentNode] + 1;

                queue.add(childIndex);
            }
        }      
    }

    public boolean hasPath(final int nodeIndex) {
        if (nodeIndex < 0 || nodeIndex > graphic.getVerticalCount()) {
            return false;
        }

        return visited[nodeIndex];
    }

    public List<Integer> path(final int endNode) {
        if (!hasPath(endNode)) {
            System.out.println("There is no path from S to " + endNode);
            return null;
        }

        final Stack<Integer> stack = new Stack<Integer>();
        int childNode = endNode;

        while (childNode >= 0 && childNode < graphic.getVerticalCount()) {
            stack.push(childNode);
            childNode = parentNodes[childNode];
        }

        int stackCount = stack.size();
        final List<Integer> res = new ArrayList<Integer>(stackCount);
        while (!stack.isEmpty()) {
            res.add(stack.pop());
        }
        
        return res;
    }

    public void showPath (List<Integer> path) {     
        for (int i = 0; i<path.size(); i++) {
            System.out.print(path.get(i));
            if( i == path.size() - 1 )
                System.out.println();
            else
                System.out.print(" -> ");
        }
    }

    public void test() {
        showPath(path(graphic.getVerticalCount() - 1));
    }

    public static void main(String[] args) {
        BFSShortestPath shortestPath = new BFSShortestPath(new Graphic(), 0);
        shortestPath.test();
    }





}