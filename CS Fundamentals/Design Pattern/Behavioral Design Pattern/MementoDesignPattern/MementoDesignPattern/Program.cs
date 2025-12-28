class Memento
{
    public string State { get; set; }
    public Memento(string state)=>State = state;
}

class Editor
{
    public string State { get; set; }
    public Memento SaveMemento()=>new Memento(State);
    public void RestoreMemento(Memento memento) => State = memento.State;
}

class History
{
    public Stack<Memento> MementoStack { get; set; } = new Stack<Memento>();
}
class Program
{
    static void Main(string[] args)
    {
        var editor = new Editor();
        var history = new History();
        editor.State = "Version 1";
        history.MementoStack.Push(new Memento(editor.State));
        editor.State = "Version 2";
        history.MementoStack.Push(new Memento(editor.State));
        editor.State = "Version 3";
        editor.RestoreMemento(history.MementoStack.Pop());
        Console.WriteLine(editor.State);
    }
}