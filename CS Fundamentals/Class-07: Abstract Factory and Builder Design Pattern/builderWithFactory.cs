using System;
using System.Collections.Generic;

public interface ILogger {
    public void Log(string message);
}

public class Logger : ILogger {
    private Logger() {}

    private static Logger _instance = null;
    private static readonly object _lock = new object();

    public static Logger GetInstance() {
        if (_instance == null) {
            lock (_lock) {
                if (_instance == null) {
                    _instance = new Logger();
                }
            }
        }
        return _instance;
    }

    public void Log(string message) {
        Console.WriteLine("This is from log - {0}",message);
    }
}

public interface ISend {
    public void Send();
}

public interface ILog {
    public void Log();
}

public interface ISave {
    public void Save();
}

public class EmailNotify : ISend, ILog, ISave {
    public string Email { get; set; }

    public void Send() {
        Console.WriteLine("Sending email to " + Email);
    }

    public void Log() {
        ILogger logger = Logger.GetInstance();
        logger.Log("Logging email to " + Email);
    }

    public void Save() {
        Console.WriteLine("Saving db to " + Email);
    }
}

public class SMSNotify : ISend, ILog, ISave {
    public string Phone { get; set; }

    public void Send() {
        Console.WriteLine("Sending SMS to " + Phone);
    }

    public void Log() {
        ILogger logger = Logger.GetInstance();
        logger.Log("Logging SMS to " + Phone);
    }

    public void Save() {
        Console.WriteLine("Saving db to " + Phone);
    }
}

public class PushNotify : ISend, ILog {
    public string Token { get; set; }

    public void Send() {
        Console.WriteLine("Sending Push to " + Token);
    }

    public void Log() {
        ILogger logger = Logger.GetInstance();
        logger.Log("Logging Push to " + Token);
    }
}

public class WhatsappNotify : ISend, ILog {
    public string Phone { get; set; }

    public void Send() {
        Console.WriteLine("Sending Whatsapp to " + Phone);
    }

    public void Log() {
        ILogger logger = Logger.GetInstance();
        logger.Log("Logging Whatsapp to " + Phone);
    }
}

public class NotifyContext {
    public ISend send { get; set; }
    public ILog log { get; set; }
    public ISave save { get; set; }

    public NotifyContext(ISend send, ILog log, ISave save) {
        this.send = send;
        this.log = log;
        this.save = save;
    }

    public void Process() {
        send.Send();
        log.Log();

        if(save != null) {
            save.Save();
        }
    }
}

public interface INotificationFactory {
    ISend CreateSender();
    ILog CreateLogger();
    ISave CreateSaver();
}

public class EmailFactory : INotificationFactory {
    public ISend CreateSender() {
        return new EmailNotify { Email = "test@test.com" };
    }

    public ILog CreateLogger() {
        return new EmailNotify { Email = "test@test.com" };
    }

    public ISave CreateSaver() {
        return new EmailNotify { Email = "test@test.com" };
    }
}

public class SMSFactory : INotificationFactory {
    public ISend CreateSender() {
        return new SMSNotify { Phone = "123456789" };
    }

    public ILog CreateLogger() {
        return new SMSNotify { Phone = "123456789" };
    }

    public ISave CreateSaver() {
        return new SMSNotify { Phone = "123456789" };
    }
}

public class PushFactory : INotificationFactory {
    public ISend CreateSender() {
        return new PushNotify { Token = "123456789" };
    }

    public ILog CreateLogger() {
        return new PushNotify { Token = "123456789" };
    }

    public ISave CreateSaver() {
        return null; // Not supported
    }
}

public class WhatsappFactory : INotificationFactory {
    public ISend CreateSender() {
        return new WhatsappNotify { Phone = "123456789" };
    }

    public ILog CreateLogger() {
        return new WhatsappNotify { Phone = "123456789" };
    }

    public ISave CreateSaver() {
        return null;
    }
}

public interface INotificationContextBuilder
{
    NotificationContextBuilder SetSender(ISend sender);
    NotificationContextBuilder SetLogger(ILog logger);
    NotificationContextBuilder SetSaver(ISave saver);
    public NotifyContext Build();
}

public class NotificationContextBuilder : INotificationContextBuilder {

    private ISend _sender = null;
    private ILog _logger = null;
    private ISave _saver = null;

    public NotificationContextBuilder SetSender(ISend sender) {
        _sender = sender;
        return this;
    }

    public NotificationContextBuilder SetLogger(ILog logger) {
        _logger = logger;
        return this;
    }

    public NotificationContextBuilder SetSaver(ISave saver) {
        _saver = saver;
        return this;
    }

    public NotifyContext Build() {
        return new NotifyContext(_sender, _logger, _saver);
    }
}

public interface INotificationContextCreator {
    public NotifyContext Create();
}

public class EmailNotificationContextCreator : INotificationContextCreator {
    
    public NotifyContext Create() {
        INotificationFactory factory = new EmailFactory();

        NotifyContext notificationContext = new NotificationContextBuilder().
            SetSender(factory.CreateSender()).
            SetLogger(factory.CreateLogger()).
            SetSaver(factory.CreateSaver()).
            Build();

        return notificationContext;
    }
}

public class SMSNotificationContextCreator : INotificationContextCreator {
    public NotifyContext Create() {
        INotificationFactory factory = new SMSFactory();

        INotificationContextBuilder notificationContextBuilder  = new NotificationContextBuilder().
            SetSender(factory.CreateSender()).
            SetLogger(factory.CreateLogger()).
            SetSaver(factory.CreateSaver());

        return notificationContextBuilder.Build();
    }
}

public class PushNotificationContextCreator : INotificationContextCreator {
    public NotifyContext Create() {
        INotificationFactory factory = new PushFactory();
        INotificationContextBuilder notificationContextBuilder  = new NotificationContextBuilder().
            SetSender(factory.CreateSender()).
            SetLogger(factory.CreateLogger()).
            SetSaver(factory.CreateSaver());

        return notificationContextBuilder.Build();
    }
}

public class WhatsappNotificationContextCreator : INotificationContextCreator {
    public NotifyContext Create() {
        INotificationFactory factory = new WhatsappFactory();
        INotificationContextBuilder notificationContextBuilder  = new NotificationContextBuilder().
            SetSender(factory.CreateSender()).
            SetLogger(factory.CreateLogger()).
            SetSaver(factory.CreateSaver());

        return notificationContextBuilder.Build();
    }
}

class Program {
    public static void Main () {
        INotificationContextCreator emailCreator = new EmailNotificationContextCreator();
        NotifyContext emailContext = emailCreator.Create();

        INotificationContextCreator smsCreator = new SMSNotificationContextCreator();
        NotifyContext smsContext = smsCreator.Create();

        INotificationContextCreator pushCreator = new PushNotificationContextCreator();
        NotifyContext pushContext = pushCreator.Create();

        INotificationContextCreator whatsappCreator = new WhatsappNotificationContextCreator();
        NotifyContext whatsappContext = whatsappCreator.Create();

        emailContext.Process();
        smsContext.Process();
        pushContext.Process();
        whatsappContext.Process();
    }
}
