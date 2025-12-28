public interface IChatMediator
{
    void SendMessage(string message, string sender);
    void AddUser(User user);
}

public class ChatMediator : IChatMediator
{
    public List<User> Users = new List<User>();
    public void SendMessage(string message, string sender)
    {
        foreach (var user in Users)
        {
            if (user.Username != sender)
            {
                user.ReceiveMessage(message);
            }
        }
    }

    public void AddUser(User user)
    {
        Users.Add(user);
    }
}

public abstract class User
{
    public IChatMediator mediator { get; set; }
    public string Username { get; set; }

    public User(IChatMediator mediator, string username)
    {
        this.mediator = mediator;
        this.Username = username;
    }
    public abstract void SendMessage(string message);
    public abstract void ReceiveMessage(string message);
}

public class ChatUser : User
{
    public ChatUser(IChatMediator mediator, string username) : base(mediator, username) {}

    public override void ReceiveMessage(string message)
    {
        Console.WriteLine($"{this.Username} receives {message}");
    }
    public override void SendMessage(string message)
    {
        Console.WriteLine($"{this.Username} sends {message}");
        mediator.SendMessage(message, Username);
    }
}


public class Program
{
    public static void Main()
    {
        IChatMediator mediator = new ChatMediator();
        
        User user1 = new ChatUser(mediator, "John");
        User user2 = new ChatUser(mediator, "Jane");
        User user3 = new ChatUser(mediator, "Jack");
        
        mediator.AddUser(user1);
        mediator.AddUser(user2);
        mediator.AddUser(user3);
        
        user1.SendMessage("Hello Everyone");
        user2.SendMessage("Hello John & Jack");
    }
}