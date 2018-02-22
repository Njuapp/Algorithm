import edu.princeton.cs.algs4.WeightedQuickUnionUF;
import edu.princeton.cs.algs4.StdOut;
public class Percolation {
    private WeightedQuickUnionUF uf;
    private int[] open;
    private int n;
    private int cnt;
    private final int top;
    private final int bottom;
    private int idx(int row, int col) {
        return (row-1)*n+(col-1);
    }
    public Percolation(int n) {               // create n-by-n grid, with all sites blocked
        if(n<=0)
            throw new java.lang.IllegalArgumentException();
        this.n = n;
        this.cnt = 0;
        this.top = n * n;
        this.bottom = n * n + 1;
        uf = new WeightedQuickUnionUF(n*n+2 );
        open = new int[n*n+2];
        open[top] = 1;
        open[bottom] = 1;
    }
    public    void open(int row, int col) {    // open site (row, col) if it is not open already
        if(row <= 0|| row > n || col <= 0 || row > n)
            throw new java.lang.IllegalArgumentException();
        if(open[idx(row,col)] == 1)
            return;
        int[][] step = new int[][]{{-1,0}, {1,0}, {0,-1}, {0,1} };
        open[idx(row,col)] = 1;
        cnt ++;
        for(int i = 0; i < 4; i++){
            int r = row + step[i][0];
            int c = col + step[i][1];
            if(c == 0||c == n + 1)
                continue;
            else if(r == 0) {
                uf.union(idx(row,col), top);
            }
            else if (r == n + 1) {
                uf.union(idx(row,col), bottom);
            }
            else if(open[idx(r,c)] == 1 && !uf.connected(idx(r,c), idx(row,col) )){
                uf.union(idx(r,c), idx(row,col));
            }
        }
    }
    public boolean isOpen(int row, int col) {
         if(row <= 0|| row > n || col <= 0 || row > n)
            throw new java.lang.IllegalArgumentException();
        return open[idx(row, col)] == 1;
    }
    public boolean isFull(int row, int col) {
         if(row <= 0|| row > n || col <= 0 || row > n)
            throw new java.lang.IllegalArgumentException();
        return uf.connected(top, idx(row, col) );
    }
   public int numberOfOpenSites() {     
       return cnt;
   }
   public boolean percolates(){
       return uf.connected(top, bottom);
   }
   public static void main(String[] args)   // test client (optional)
   {}
}