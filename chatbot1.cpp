#include <bits/stdc++.h>
using namespace std;
class BookStoreBot
{
private:
    string name;

    unordered_map<string, string> responses;

public:
    BookStoreBot(string name)
    {
        this->name = name;
    }
    void welcomeMessage()
    {
        cout << "Welcome to Book Heaven. I am " << name << " .\n How I Can Assist You Today ? \n";
    }
    void addResponse(string trigger, string message)
    {
        responses[trigger] = message;
    }
    void handleExit()
    {
        cout << "Bot: Thank you for visiting Bookworm Haven! Have a wonderful day!\n";
        exit(0);
    }
    void processInput(string input)
    {

        if (input == "exit")
        {
            handleExit();
            return;
        }
        string linput = input;
        transform(linput.begin(), linput.end(), linput.begin(), ::tolower);
        bool matched = false;
        for (auto resp : responses)
        {
            if (linput.find(resp.first) != string::npos)
            {
                cout << "Bot : " << resp.second << endl;
                matched = true;
                break;
            }
        }
        if (!matched)
        {
            cout << " Bot : I dont have knowledge about it as now !!!" << endl;
        }
    }
};
int main()
{
    cout << "hello" << endl;
    BookStoreBot bot("Bookstore Bot");
    bot.welcomeMessage();
    bot.addResponse("search for a book", "You can search for a book using our website's search bar.");

    bot.addResponse("search", "You can search for a book using our website's search bar.");
    bot.addResponse("find a book", "You can search for a book using our website's search bar.");
    bot.addResponse("look for a book", "You can search for a book using our website's search bar.");
    bot.addResponse("search book", "You can search for a book using our website's search bar.");
    bot.addResponse("find book", "You can search for a book using our website's search bar.");
    bot.addResponse("look book", "You can search for a book using our website's search bar.");
    bot.addResponse("search book online", "You can search for a book using our website's search bar.");
    bot.addResponse("look up a book", "You can search for a book using our website's search bar.");
    bot.addResponse("browse for a book", "You can search for a book using our website's search bar.");
    bot.addResponse("locate a book", "You can search for a book using our website's search bar.");

    bot.addResponse("genres of books", "We offer a wide range of genres including fiction, non-fiction, mystery, romance, and more.");
    bot.addResponse("genres", "We offer a wide range of genres including fiction, non-fiction, mystery, romance, and more.");
    bot.addResponse("types of books", "We offer a wide range of genres including fiction, non-fiction, mystery, romance, and more.");
    bot.addResponse("categories of books", "We offer a wide range of genres including fiction, non-fiction, mystery, romance, and more.");
    bot.addResponse("book categories", "We offer a wide range of genres including fiction, non-fiction, mystery, romance, and more.");
    bot.addResponse("book genres", "We offer a wide range of genres including fiction, non-fiction, mystery, romance, and more.");
    bot.addResponse("kinds of books", "We offer a wide range of genres including fiction, non-fiction, mystery, romance, and more.");
    bot.addResponse("types of literature", "We offer a wide range of genres including fiction, non-fiction, mystery, romance, and more.");

    bot.addResponse("place an order", "You can place an order by adding items to your cart and proceeding to checkout.");
    bot.addResponse("order", "You can place an order by adding items to your cart and proceeding to checkout.");
    bot.addResponse("purchase", "You can place an order by adding items to your cart and proceeding to checkout.");
    bot.addResponse("buy", "You can place an order by adding items to your cart and proceeding to checkout.");
    bot.addResponse("buy a book", "You can place an order by adding items to your cart and proceeding to checkout.");
    bot.addResponse("order a book", "You can place an order by adding items to your cart and proceeding to checkout.");
    bot.addResponse("purchase a book", "You can place an order by adding items to your cart and proceeding to checkout.");
    bot.addResponse("add to cart", "You can place an order by adding items to your cart and proceeding to checkout.");
    bot.addResponse("checkout", "You can place an order by adding items to your cart and proceeding to checkout.");
    bot.addResponse("complete my purchase", "You can place an order by adding items to your cart and proceeding to checkout.");

    bot.addResponse("track my order", "You can track your order by logging into your account and checking the order status.");
    bot.addResponse("track", "You can track your order by logging into your account and checking the order status.");
    bot.addResponse("check my order status", "You can track your order by logging into your account and checking the order status.");
    bot.addResponse("view my order", "You can track your order by logging into your account and checking the order status.");
    bot.addResponse("track shipment", "You can track your order by logging into your account and checking the order status.");
    bot.addResponse("see delivery status", "You can track your order by logging into your account and checking the order status.");
    bot.addResponse("where is my order", "You can track your order by logging into your account and checking the order status.");

    bot.addResponse("return policy", "Our return policy allows returns within 30 days of purchase with a valid receipt.");
    bot.addResponse("return", "Our return policy allows returns within 30 days of purchase with a valid receipt.");
    bot.addResponse("exchange policy", "Our return policy allows returns within 30 days of purchase with a valid receipt.");
    bot.addResponse("refund policy", "Our return policy allows returns within 30 days of purchase with a valid receipt.");
    bot.addResponse("return merchandise", "Our return policy allows returns within 30 days of purchase with a valid receipt.");
    bot.addResponse("exchange merchandise", "Our return policy allows returns within 30 days of purchase with a valid receipt.");
    bot.addResponse("refund merchandise", "Our return policy allows returns within 30 days of purchase with a valid receipt.");

    bot.addResponse("gift wrapping", "Yes, we offer gift wrapping services for an additional fee.");
    bot.addResponse("gift", "Yes, we offer gift wrapping services for an additional fee.");
    bot.addResponse("gift wrap", "Yes, we offer gift wrapping services for an additional fee.");
    bot.addResponse("wrapping services", "Yes, we offer gift wrapping services for an additional fee.");
    bot.addResponse("wrap my gift", "Yes, we offer gift wrapping services for an additional fee.");
    bot.addResponse("gift package", "Yes, we offer gift wrapping services for an additional fee.");
    bot.addResponse("gift box", "Yes, we offer gift wrapping services for an additional fee.");

    bot.addResponse("contact customer support", "You can contact our customer support team at support@bookwormhaven.com.");
    bot.addResponse(" support", "You can contact our customer support team at support@bookwormhaven.com.");
    bot.addResponse("get in touch with support", "You can contact our customer support team at support@bookwormhaven.com.");
    bot.addResponse("customer service contact", "You can contact our customer support team at support@bookwormhaven.com.");
    bot.addResponse("reach out for help", "You can contact our customer support team at support@bookwormhaven.com.");
    bot.addResponse("need assistance", "You can contact our customer support team at support@bookwormhaven.com.");
    bot.addResponse("customer support", "You can contact our customer support team at support@bookwormhaven.com.");
    string uinput;
    while (true)
    {
        cout << "User : ";
        getline(cin, uinput);
        bot.processInput(uinput);
    }
    return 0;
}