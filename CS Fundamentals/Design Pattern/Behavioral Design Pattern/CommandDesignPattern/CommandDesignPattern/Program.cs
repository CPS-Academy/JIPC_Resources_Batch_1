public interface ICommand
{
    void Execute();
}

public class Light
{
    public void TurnOn()
    {
        Console.WriteLine("Turned on");
    }

    public void TurnOff()
    {
        Console.WriteLine("Turned off");
    }
}

public class LightOnCommand : ICommand
{
    private Light _light;

    public LightOnCommand(Light light)
    {
        _light = light;
    }
    public void Execute()
    {
        _light.TurnOn();
    }
}
public class LightOffCommand : ICommand
{
    private Light _light;

    public LightOffCommand(Light light)
    {
        _light = light;
    }
    public void Execute()
    {
        _light.TurnOff();
    }
}

public class RemoteControl
{
    private ICommand _command;

    public void SetCommand(ICommand command)
    {
        _command = command;
    }

    public void PressButton()
    {
        _command.Execute();
    }
}
class Program
{
    static void Main(string[] args)
    {
        Light light = new Light();
        ICommand lightOnCommand = new LightOnCommand(light);
        ICommand lightOffCommand = new LightOffCommand(light);
        //
        
        RemoteControl remoteControl = new RemoteControl();
        remoteControl.SetCommand(lightOnCommand);
        remoteControl.PressButton();
        remoteControl.SetCommand(lightOffCommand);
        remoteControl.PressButton();
        
    }
}