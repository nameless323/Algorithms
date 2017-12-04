//
// Copyright (C) Alexandr Vorontsov 2016.
// Distributed under the MIT License (license terms are at http://opensource.org/licenses/MIT).
//

#pragma once

template<class T> 
inline void SafeDelete(T*& ptr) 
{ 
    delete ptr; 
    ptr = nullptr; 
}
