import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
public class BFS {
	public static void bfs(int[][] arr, int sv) {
		boolean[] visited = new boolean[arr.length];
		Queue<Integer> q = new LinkedList<Integer>();
		q.add(sv);
		while (!q.isEmpty()) {
			int retval = q.poll();
			System.out.println(retval);
			visited[retval] = true;
			for (int i = 0; i < arr.length; i++) {
				if (i != sv && !visited[i] && arr[retval][i] > 0) {
					q.add(i);
					visited[i] = true;
				}
			}
		}
	}

	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		int N = scn.nextInt();
		int[][] graph = new int[N][N];
		int E = scn.nextInt();
		for (int i = 0; i < E; i++) {
			int f = scn.nextInt();
			int s = scn.nextInt();
			graph[f][s] = 1;
			graph[s][f] = 1;
		}
		boolean[] visited = new boolean[N];
		bfs(graph, 0);
	}
}
