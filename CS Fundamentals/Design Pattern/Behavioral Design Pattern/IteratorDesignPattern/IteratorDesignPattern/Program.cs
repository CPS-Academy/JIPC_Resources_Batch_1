public interface IPlaylistIterator
{
    bool HasNext();
    Song Next();
}

public interface IPlayList
{
    IPlaylistIterator CreateIterator();
}

public class PlayList : IPlayList
{
    private List<Song> _playlist = new List<Song>();

    public void AddSong(Song song)
    {
        _playlist.Add(song);
    }
    public IPlaylistIterator CreateIterator()
    {
        return new PlaylistIterator(_playlist);
    }
}

public class PlaylistIterator : IPlaylistIterator
{
    private List<Song> _songs = new List<Song>();
    public int index = 0;

    public PlaylistIterator(List<Song> songs)
    {
        _songs = songs;
    }

    public bool HasNext()
    {
        return index < _songs.Count;
    }

    public Song Next()
    {
        return _songs[index++];
    }
    
}
public class Song
{
    public string Title { get; set; }
    public string Artist { get; set; }

    public Song(string title, string artist)
    {
        Title = title;
        Artist = artist;
    }
}

public class Program
{
    public static void Main()
    {
        var playList = new PlayList();
        playList.AddSong(new Song("Song 1","Artist 1"));
        playList.AddSong(new Song("Song 2","Artist 2"));
        playList.AddSong(new Song("Song 3","Artist 3"));
        
        var playListIterator = playList.CreateIterator();

        while (playListIterator.HasNext())
        {
            var song = playListIterator.Next();
            Console.WriteLine($"{song.Title} -  {song.Artist}");
        }
    }
}