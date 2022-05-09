import java.util.*;

class Main {
    private int V;
    private LinkedList<Integer> adj[];

    @SuppressWarnings("unchecked") Main(int v){
        V = v;
        adj = new LinkedList[v];
        for (int i = 0; i < v; ++i){
            adj[i] = new LinkedList();
        }
    }

    void addEdge(int v, int w){
        adj[v].add(w);
        adj[w].add(v);
    }

    void DFS(int v, int end, boolean visited[]){

        visited[v] = true;
        System.out.print(v + " ");

        Iterator<Integer> i = adj[v].listIterator();

        while (i.hasNext()){
            int n = i.next();
            if (!visited[n]){

                DFS(n, end, visited);
            }
        }

    }

    public static void main(String args[]){
        Main g = new Main(4);
        boolean visited[] = new boolean[4];

        g.addEdge(0, 1);
        g.addEdge(0, 2);
        g.addEdge(1, 2);
        g.addEdge(2, 3);

        System.out.println("Route of DFS starting from vertex " + 3 + ", with ending vertex " + 0 + ": ");
        g.DFS(3, 0, visited);
    }
}
