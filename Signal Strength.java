import java.util.Scanner;

public class SignalStrength {
	
	static int count = 1;
	
	public static void add_edge(int[][] graph, int v, int w){
		graph[w][v] = 1;
	}
	public static void add_weight(double[][] connections, int v, int w, double weight){
		connections[v][w] = weight;
	}
	
	public static void calculate(int[][] graph, double[][] connections, double[] weight){
		int size = weight.length;
		double[] maxvals = new double[size];
		maxvals[0] = weight[0];
		for (int i = 1; i < size; i++){
			for (int j = 0; j < size; j++){
				if (graph[i][j] == 1){
					double poss = maxvals[j]*connections[j][i]*weight[i];
					maxvals[i] = Math.max(maxvals[i], poss);
				}
			}
		}
		if (maxvals[size-1] == 0.0){
			boolean connected = false;
			for (int i = 0; i < size; i++){
				if (graph[size-1][i] == 1){
					connected = true;
					break;
				}
			}
			if (connected){
				System.out.println("Network "+count+": " + String.format("%.2f", maxvals[size-1]));
			}
			else System.out.println("Network "+count+": 0.00");
		}
			
		else {
			System.out.println("Network "+count+": " + String.format("%.2f", maxvals[size-1]));
		}
		count++;
		
	}
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		while (true){
			int N = scanner.nextInt();
			if (N == 0) break;
			int[][] graph = new int[N][N];
			double[] weights = new double[N];
			double[][] connections = new double[N][N];
			
			for (int i = 0; i < N; i++){
				double amp = scanner.nextDouble();
				weights[i] = amp;
				int M = scanner.nextInt();
				for (int j = 0; j < M; j++){
					int w = scanner.nextInt();
					double weight = scanner.nextDouble();
					add_weight(connections,i,w,weight);
					add_edge(graph,i,w);
				}
			}
			calculate(graph,connections,weights);
		}
	}
}
