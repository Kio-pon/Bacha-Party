int main()
{ 
    Crystal Fire, Water;
    cout << "Now there are " << Fire.count << " crystals.\n";
    { 
        Crystal Fire, Water, Earth, Wind;
        cout << "Now there are " << Fire.count << " crystals.\n";
    }
    cout << "Now there are " << Fire.count << " crystals.\n";
    Crystal Earth;
    cout << "Now there are " << Earth.count << " crystals.\n";
}

// Output :
// Now there are 2 crystals.
// Now there are 6 crystals.
// Now there are 2 crystals.
// Now there are 3 crystals.
// Explanation:
// Notice how four crystals are created inside the inner block, 
// and then they are destroyed when program control leaves that block, 
// reducing the global number of crystals from 6 to 2.