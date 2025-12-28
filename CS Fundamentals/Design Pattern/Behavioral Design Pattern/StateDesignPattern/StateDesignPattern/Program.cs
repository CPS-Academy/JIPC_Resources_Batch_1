interface IMediaState
{
    void Play(MediaPlayer player);
    void Pause(MediaPlayer player);
    void Stop(MediaPlayer player);
}

class PlayingState : IMediaState
{
    public void Play(MediaPlayer player)
    {
        Console.WriteLine("Already Playing");   
    }

    public void Pause(MediaPlayer player)
    {
        Console.WriteLine("Pasuing Media");
        player.SetState(new PausingState());
    }

    public void Stop(MediaPlayer player)
    {
        Console.WriteLine("Stopping Media");
        player.SetState(new StoppingState());
    }
}
class PausingState : IMediaState
{
    public void Play(MediaPlayer player)
    {
        Console.WriteLine("Playing Media"); 
        player.SetState(new PlayingState());
    }

    public void Pause(MediaPlayer player)
    {
        Console.WriteLine("Already Pasuing");
    }

    public void Stop(MediaPlayer player)
    {
        Console.WriteLine("Stopping Media");
        player.SetState(new StoppingState());
    }
}
class StoppingState : IMediaState
{
    public void Play(MediaPlayer player)
    {
        Console.WriteLine("Playing Media"); 
        player.SetState(new PlayingState());
    }

    public void Pause(MediaPlayer player)
    {
        Console.WriteLine("Pasuing Media");
        player.SetState(new PausingState());
    }

    public void Stop(MediaPlayer player)
    {
        Console.WriteLine("Already Stopping");
    }
}
class MediaPlayer
{
    private IMediaState _state = new StoppingState();

    public void SetState(IMediaState state)
    {
        _state = state;
    }
    public void Play()=>_state.Play(this);
    public void Pause()=>_state.Pause(this);
    public void Stop()=>_state.Stop(this);
}
class Program
{
    static void Main()
    {
        MediaPlayer player = new MediaPlayer();
        player.Play();
        player.Play();
        player.Pause();
        player.Pause();
        player.Play();
        player.Stop();
        player.Pause();
    }
}