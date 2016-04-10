import java.util.*;
import java.io.*;
import java.math.*;

//works for large input
public class coinjam {
	public static BigInteger div(BigInteger val)
	{
		if(val.mod(BigInteger.valueOf(2)).compareTo(BigInteger.ZERO) == 0)
			return BigInteger.valueOf(2);
		if(val.mod(BigInteger.valueOf(3)).compareTo(BigInteger.ZERO) == 0)
			return BigInteger.valueOf(3);
		if(val.mod(BigInteger.valueOf(5)).compareTo(BigInteger.ZERO) == 0)
			return BigInteger.valueOf(5);
		if(val.mod(BigInteger.valueOf(7)).compareTo(BigInteger.ZERO) == 0)
			return BigInteger.valueOf(7);
		return BigInteger.ZERO;
	}
    public static void main(String[] args) 
    {
	    Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
	    int T = in.nextInt();  // Scanner has functions to read ints, longs, strings, chars, etc.
	    
	    for (int t = 1; t <= T; ++t) 
	    {
	        int N = in.nextInt();
	        int J = in.nextInt();
	        System.out.printf("Case #%d:\n", t);

	      	String helper = new String(new char[N-2]).replace('\0', '0');
	      	String coin = "1" + helper + "1";

	      	int count = 0;

	      	while(count < J)
	      	{
		      	boolean flag = true;
		      	BigInteger v[] = new BigInteger[9];
		      	int b;
		      	for(b = 2; flag == true && b <= 10; ++b)
		      	{
		      		BigInteger val = new BigInteger(coin, b);

		      		//System.out.printf("%s", val.toString());

		      		BigInteger d = div(val);

		      		if(d.compareTo(BigInteger.ZERO) == 0)
		      			flag = false;
		      		else
		      			v[b-2] = d;
		      	}
		      	
		      	if(flag == true)
		      	{
		      		System.out.printf("%s", coin);
		      		++count;

		      		for(b = 0; b <= 8; ++b)
		      			System.out.printf(" %s", v[b].toString());
		      		System.out.printf("\n");
		      	}
		      	
		      	int k = helper.length()-1;
				
				while(helper.charAt(k) == '1')
				{
					helper = helper.substring(0,k) + '0' + helper.substring(k+1);
					k--;
				}
				helper = helper.substring(0,k) + '1' + helper.substring(k+1);
				coin = "1" + helper + "1";
				//System.out.printf("%s\n", coin);
		    }
		     // System.out.println("Case #" + t + ": " + coin);
	    }
    }
}