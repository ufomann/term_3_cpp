struct Base { 
    int a;
}; 

struct D1 : Base {
};

struct D2 : Base { 
}; 

struct D3 : D1, D2 { 
};

Base const * D1BaseToD2Base( Base const * base ) {
	auto ans = static_cast<const Base *>(static_cast<const D2 *>(static_cast<const D3*>(static_cast<const D1*>(base))));
    return ans;
}