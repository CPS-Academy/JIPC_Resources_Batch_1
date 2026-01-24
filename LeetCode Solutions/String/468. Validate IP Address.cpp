class Solution {
    string IPv4 = "IPv4";
    string IPv6 = "IPv6";
    string NEIGTHER = "Neither";

    bool isValidlySeparated(string& ipAddress, char separator, int partCount) {
        int separatorCount = 0;
        for(char ch: ipAddress) {
            separatorCount += (ch == separator);
        }
        return separatorCount == partCount;
    }

    bool isValidIpv4Address(string ipAddress) {
        ipAddress += '.';
        if(!isValidlySeparated(ipAddress, '.', 4)) {
            return false;
        }

        // cout << "value\n";

        int ipValue = 0;
        int previousDotPosition = -1;
        string part = "";
        for(int i = 0; i < ipAddress.size(); i++) {
            char ch = ipAddress[i];
            if(ch == '.') {
                if(previousDotPosition + 1 == i || (part.size() > 1 && part[0] == '0')) {
                    return false;
                }

                part = "";
                previousDotPosition = i;
                ipValue = 0;
            }
            else if('0' <= ch && ch <= '9'){
                part += ch;
                ipValue = 10*ipValue + ch - '0';
                if(ipValue > 255) {
                    return false;
                }
            }
            else {
                return false;
            }
        }

        return true;
    }

    bool isValidIpv6Address(string ipAddress) {

        ipAddress += ':';
        if(!isValidlySeparated(ipAddress, ':', 8)){
            return false;
        }

        int digitLength = 0;
        int prevColonPosition = -1;
        for(int i = 0; i < ipAddress.size(); i++) {
            char ch = ipAddress[i];
            if(ch == ':') {
                digitLength = 0;

                if(prevColonPosition + 1 == i) return false;
                prevColonPosition = i;
            }
            else if(('0' <= ch && ch <= '9') ||
                    ('a' <= ch && ch <= 'f') || 
                    ('A' <= ch && ch <= 'F')) {
                    digitLength++;
                    if(digitLength > 4) return false;
            }
            else return false;
        }
        return true;
    }
public:
    string validIPAddress(string queryIP) {
        if(isValidIpv4Address(queryIP)) {
            return IPv4;
        }
        if(isValidIpv6Address(queryIP)) {
            return IPv6;
        }
        return NEIGTHER;
    }
};
