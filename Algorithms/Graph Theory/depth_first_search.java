import java.util.Scanner;
public class DFS {
	public static void dfs(int[][] arr, int sv, boolean[] visited) {
		System.out.println(sv);
		visited[sv] = true;
		for (int i = 0; i < arr.length; i++) {
			if (i != sv && !visited[i] && arr[sv][i] > 0)
				dfs(arr, i, visited);
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
  	        dfs(graph, 0, visited);
	}
}
