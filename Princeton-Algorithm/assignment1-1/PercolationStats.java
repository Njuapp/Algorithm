import edu.princeton.cs.algs4.StdRandom;
import edu.princeton.cs.algs4.StdStats;
public class PercolationStats{
   private double[] prob;
   private int T;
   public PercolationStats(int n, int trials)    // perform trials independent experiments on an n-by-n grid
   {
       if(trials<=0 || n <= 0)
           throw new java.lang.IllegalArgumentException();
       prob = new double[trials];
       T = trials;
       for(int i = 0; i < trials; i++){
           Percolation perc = new Percolation(n);
           
           while(!perc.percolates()){
               int x = StdRandom.uniform(1, n+1);
               int y = StdRandom.uniform(1, n+1);
               if(!perc.isOpen(x,y))
                   perc.open(x, y);
           }
           prob[i] = perc.numberOfOpenSites() / (double)(n*n);
       }
   }
   public double mean()                          // sample mean of percolation threshold
   {
       return StdStats.mean(prob);
   }
   public double stddev()                        // sample standard deviation of percolation threshold
   {
       return StdStats.stddev(prob);
   }
   public double confidenceLo()                  // low  endpoint of 95% confidence interval
   {
       return mean() - 1.96 * stddev() / Math.sqrt(T);
   }
   public double confidenceHi()                  // high endpoint of 95% confidence interval
   {
       return mean() + 1.96 * stddev() / Math.sqrt(T);
   }
   
   public static void main(String[] args)        // test client (described below)
   {
       PercolationStats percst = new PercolationStats(20, 100);
       System.out.println("mean="+percst.mean()+",stddev="+percst.stddev()+",conf interval=["+percst.confidenceLo()+","+percst.confidenceHi()+"]");
   }
   
}