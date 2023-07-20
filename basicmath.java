public class basicmath {
    static int countdigit(int n){
        String s = Integer.toString(n);
        return s.length();
    }
    
    static int reverse(int n){
        int y=0;
        while(n>0){
            int d =n%10;
            y = y*10+d;
            n=n/10;
        }
        return y;
    }
    
    static int gcd(int a,int b){
        if(b==0){
            return a;
        }else return gcd(b,a%b);
    }
    
    static boolean ArmstrongNumber(int n)
    {
        int originalno = n;
        int count = 0;
        int temp = n;
        while (temp != 0)
        {
            count++;
            temp = temp / 10;
        }
        int sumofpower = 0;
        while (n != 0)
        {
            int digit = n % 10;
            sumofpower += Math.pow(digit,count);
            n /= 10;
        }
        return (sumofpower == originalno);
    }
    
    static void printDivisors(int n){
     for(int i =1;i<=n;i++){
        if(n%i==0){
            System.out.print(i+" ");
        }
        System.out.println();
     }
    }
    
    static boolean Isprime(int n){
        for(int i=2;i<n;i++){
            if(i%n==0)return true;
            }
            return false;
    }
    public static void main(String[] args) {
       // int a=2,b=5;
       // int ans =gcd(a,b);
        //System.out.println(ans);

       /*no of divisors are there ..................... */
        // int n = 12;
        // printDivisors(n);

 /*is  number prime no or  not.......................... */
        //  int n = 11;
        //  boolean ans = (Isprime(n));
        //  if(n!=1 || ans == true){
        //     System.out.println("prime number");
        //  }else{
        //     System.out.println("Not prime number");
        //  }
        
/*Armstrong number................................... */
       // int n1 = 1634;
    // if (ArmstrongNumber(n1))
    // {
    //     System.out.println("Yes, it is an Armstrong Number\n");
    // }
    // else
    // {
    //     System.out.println("No, it is not an Armstrong Number\n");
    // }

/*number is palindrome or not.......................... */
        //int n = 123321;
        //int dummy = n;
        //int y = reverse(n);
        //if(y==dummy)
       //System.out.println("Number is a palindrome");
       //else
       //System.out.println("Number is not a palindrome");
    }
}
