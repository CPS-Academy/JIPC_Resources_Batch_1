
public interface IBankAccount
{
    void ShowBalance();
    void Withdraw(double amount);
}


public class RealBankAccount : IBankAccount
{
    private double _balance;

    public RealBankAccount(double amount)
    {
        _balance = amount;
    }

    public void ShowBalance()
    {
        Console.WriteLine("Balance: " + _balance);
    }

    public void Withdraw(double amount)
    {
        _balance -= amount;
        Console.WriteLine("Withdraw: " + amount);
        Console.WriteLine("Balance: " + _balance);
    }
}

public class BankAccountProxy : IBankAccount
{
    private IBankAccount _realBankAccount;
    private string _userRole;

    public BankAccountProxy(double balance, string userRole)
    {
        _realBankAccount = new RealBankAccount(balance);
        _userRole = userRole;
    }
    public void ShowBalance()
    {
        _realBankAccount.ShowBalance();
    }

    public void Withdraw(double amount)
    {
        if (_userRole != "Admin")
        {
            Console.WriteLine("Access Denied, Only Admin can perform this operation!");
            return;
        }
        _realBankAccount.Withdraw(amount);
    }
}

class Program
{
    static void Main(string[] args)
    {
        IBankAccount adminAccount = new BankAccountProxy(1000, "Admin");
        IBankAccount userAccount = new BankAccountProxy(1000, "User");
        
        userAccount.ShowBalance();
        userAccount.Withdraw(100);
        adminAccount.ShowBalance();
        adminAccount.Withdraw(200);
    }
}