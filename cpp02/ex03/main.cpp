#include "Point.hpp"
#include <iostream>

int main() {
    std::cout << "=== Point BSP Testing ===" << std::endl;
    
    // Define a triangle with vertices A(0,0), B(5,0), C(2.5,5)
    Point a(0.0f, 0.0f);
    Point b(5.0f, 0.0f);
    Point c(2.5f, 5.0f);
    
    std::cout << "Triangle vertices:" << std::endl;
    std::cout << "A: (" << a.getX() << ", " << a.getY() << ")" << std::endl;
    std::cout << "B: (" << b.getX() << ", " << b.getY() << ")" << std::endl;
    std::cout << "C: (" << c.getX() << ", " << c.getY() << ")" << std::endl;
    std::cout << std::endl;
    
    // Test points inside the triangle
    std::cout << "Testing points INSIDE the triangle:" << std::endl;
    Point inside1(2.5f, 1.0f);
    Point inside2(1.0f, 1.0f);
    Point inside3(3.0f, 2.0f);
    
    std::cout << "Point (" << inside1.getX() << ", " << inside1.getY() << "): " 
              << (bsp(a, b, c, inside1) ? "INSIDE" : "OUTSIDE") << std::endl;
    std::cout << "Point (" << inside2.getX() << ", " << inside2.getY() << "): " 
              << (bsp(a, b, c, inside2) ? "INSIDE" : "OUTSIDE") << std::endl;
    std::cout << "Point (" << inside3.getX() << ", " << inside3.getY() << "): " 
              << (bsp(a, b, c, inside3) ? "INSIDE" : "OUTSIDE") << std::endl;
    std::cout << std::endl;
    
    // Test points outside the triangle
    std::cout << "Testing points OUTSIDE the triangle:" << std::endl;
    Point outside1(-1.0f, 0.0f);
    Point outside2(6.0f, 0.0f);
    Point outside3(2.5f, 6.0f);
    Point outside4(0.0f, -1.0f);
    
    std::cout << "Point (" << outside1.getX() << ", " << outside1.getY() << "): " 
              << (bsp(a, b, c, outside1) ? "INSIDE" : "OUTSIDE") << std::endl;
    std::cout << "Point (" << outside2.getX() << ", " << outside2.getY() << "): " 
              << (bsp(a, b, c, outside2) ? "INSIDE" : "OUTSIDE") << std::endl;
    std::cout << "Point (" << outside3.getX() << ", " << outside3.getY() << "): " 
              << (bsp(a, b, c, outside3) ? "INSIDE" : "OUTSIDE") << std::endl;
    std::cout << "Point (" << outside4.getX() << ", " << outside4.getY() << "): " 
              << (bsp(a, b, c, outside4) ? "INSIDE" : "OUTSIDE") << std::endl;
    std::cout << std::endl;
    
    // Test points on vertices (should return FALSE)
    std::cout << "Testing points ON VERTICES (should be OUTSIDE):" << std::endl;
    std::cout << "Point A (" << a.getX() << ", " << a.getY() << "): " 
              << (bsp(a, b, c, a) ? "INSIDE" : "OUTSIDE") << std::endl;
    std::cout << "Point B (" << b.getX() << ", " << b.getY() << "): " 
              << (bsp(a, b, c, b) ? "INSIDE" : "OUTSIDE") << std::endl;
    std::cout << "Point C (" << c.getX() << ", " << c.getY() << "): " 
              << (bsp(a, b, c, c) ? "INSIDE" : "OUTSIDE") << std::endl;
    std::cout << std::endl;
    
    // Test points on edges (should return FALSE)
    std::cout << "Testing points ON EDGES (should be OUTSIDE):" << std::endl;
    Point edge1(2.5f, 0.0f);   // Middle of AB
    Point edge2(1.25f, 2.5f);  // Middle of AC
    Point edge3(3.75f, 2.5f);  // Middle of BC
    
    std::cout << "Point on AB (" << edge1.getX() << ", " << edge1.getY() << "): " 
              << (bsp(a, b, c, edge1) ? "INSIDE" : "OUTSIDE") << std::endl;
    std::cout << "Point on AC (" << edge2.getX() << ", " << edge2.getY() << "): " 
              << (bsp(a, b, c, edge2) ? "INSIDE" : "OUTSIDE") << std::endl;
    std::cout << "Point on BC (" << edge3.getX() << ", " << edge3.getY() << "): " 
              << (bsp(a, b, c, edge3) ? "INSIDE" : "OUTSIDE") << std::endl;
    std::cout << std::endl;
    
    // Test with a different triangle
    std::cout << "=== Testing with different triangle ===" << std::endl;
    Point a2(-1.0f, -1.0f);
    Point b2(3.0f, -1.0f);
    Point c2(1.0f, 3.0f);
    
    std::cout << "Triangle 2 vertices:" << std::endl;
    std::cout << "A2: (" << a2.getX() << ", " << a2.getY() << ")" << std::endl;
    std::cout << "B2: (" << b2.getX() << ", " << b2.getY() << ")" << std::endl;
    std::cout << "C2: (" << c2.getX() << ", " << c2.getY() << ")" << std::endl;
    
    Point test1(1.0f, 0.0f);   // Should be inside
    Point test2(0.0f, 2.0f);   // Should be outside
    Point test3(5.0f, 0.0f);   // Should be outside
    
    std::cout << "Point (" << test1.getX() << ", " << test1.getY() << "): " 
              << (bsp(a2, b2, c2, test1) ? "INSIDE" : "OUTSIDE") << std::endl;
    std::cout << "Point (" << test2.getX() << ", " << test2.getY() << "): " 
              << (bsp(a2, b2, c2, test2) ? "INSIDE" : "OUTSIDE") << std::endl;
    std::cout << "Point (" << test3.getX() << ", " << test3.getY() << "): " 
              << (bsp(a2, b2, c2, test3) ? "INSIDE" : "OUTSIDE") << std::endl;
    
    return 0;
}
