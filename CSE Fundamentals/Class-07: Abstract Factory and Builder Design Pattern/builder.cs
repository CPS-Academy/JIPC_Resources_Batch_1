using System;
using System.Collections.Generic;

public class HttpRequest {
    public string _method;
    public string _uri;
    public string _body;
    public Dictionary<string, string> _headers = new Dictionary<string, string>();
    public Dictionary<string, string> _queryParams = new Dictionary<string, string>();

    public void Send () {
        Console.WriteLine("Sending request...");
        Console.WriteLine("Method: " + _method);
        Console.WriteLine("Uri: " + _uri);
        Console.WriteLine("Body: " + _body);
        Console.WriteLine("Headers: " + string.Join(", ", _headers));
        Console.WriteLine("Query Params: " + string.Join(", ", _queryParams));
        Console.WriteLine("Request sent!");
    }
}

public class HttpRequestBuilder {
    private HttpRequest _request = new HttpRequest();

    public HttpRequestBuilder SetMethod (string method) {
        _request._method = method;
        return this;
    }

    public HttpRequestBuilder SetUri (string uri) {
        _request._uri = uri;
        return this;
    }

    public HttpRequestBuilder SetBody (string body) {
        _request._body = body;
        return this;
    }

    public HttpRequestBuilder SetHeader (string key, string value) {
         _request._headers[key] = value;
        return this;
    }

    public HttpRequestBuilder SetQueryParam (string key, string value) {
        _request._queryParams[key] = value;
        return this;
    }

    public HttpRequest Build() {
        return _request;
    }
}

class Program {
    public static void Main () {
        HttpRequest request = new HttpRequestBuilder()
            .SetMethod("GET")
            .SetUri("http://example.com")
            .SetBody("body")
            .SetHeader("Content-Type", "application/json")
            .SetQueryParam("param1", "value1")
            .Build();

        request.Send();
    }
}
