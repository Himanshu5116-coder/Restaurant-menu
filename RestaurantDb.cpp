#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct MenuItem {
    string name;
    string category;
    float price;
    bool available;
    vector<string> tags;
    string description;
    bool isJainAvailable;
    bool isVegan;
};

vector<MenuItem> menu = {
    {
        "Paneer Butter Masala",
        "Main Course",
        220.0,
        true,
        {"north indian", "spicy", "paneer"},
        "Cottage cheese cooked in rich tomato butter gravy.",
        true,
        false
    },
    {
        "Masala Dosa",
        "South Indian",
        120.0,
        true,
        {"crispy", "vegan", "breakfast"},
        "Crispy rice crepe stuffed with spicy mashed potatoes.",
        false,
        true
    },
    {
        "Rajma Chawal",
        "Combo Meals",
        150.0,
        true,
        {"punjabi", "protein-rich"},
        "Kidney beans curry served with steamed rice.",
        false,
        true
    },
    {
        "Gobi Manchurian",
        "Starters",
        130.0,
        true,
        {"indo-chinese", "spicy"},
        "Fried cauliflower tossed in Manchurian sauce.",
        true,
        true
    },
    {
        "Vegetable Biryani",
        "Main Course",
        180.0,
        true,
        {"hyderabadi", "spicy"},
        "Fragrant rice cooked with mixed vegetables and spices.",
        false,
        true
    },
    {
        "Dal Tadka",
        "Main Course",
        130.0,
        true,
        {"north indian", "mild"},
        "Yellow lentils cooked and tempered with spices.",
        true,
        true
    },
    {
        "Idli Sambar",
        "South Indian",
        90.0,
        true,
        {"light", "steamed"},
        "Steamed rice cakes served with spicy lentil soup.",
        false,
        true
    },
    {
        "Palak Paneer",
        "Main Course",
        200.0,
        true,
        {"healthy", "iron-rich"},
        "Cottage cheese cooked in spinach gravy.",
        true,
        false
    },
    {
        "Pav Bhaji",
        "Snacks",
        100.0,
        true,
        {"mumbai", "spicy", "street food"},
        "Mixed vegetable mash served with buttered pav.",
        true,
        false
    },
    {
        "Aloo Paratha",
        "Breakfast",
        90.0,
        true,
        {"punjabi", "stuffed", "butter"},
        "Whole wheat bread stuffed with spiced potato filling.",
        false,
        false
    }
};