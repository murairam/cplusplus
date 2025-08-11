#include "Point.hpp"
#include <iostream>

int main() {
    
    // Test 1: Basic triangle - Right triangle
    std::cout << "\n🔸 TEST 1: Right Triangle A(0,0), B(4,0), C(0,3)" << std::endl;
    Point a1(0.0f, 0.0f);
    Point b1(4.0f, 0.0f);
    Point c1(0.0f, 3.0f);
    
    std::cout << "Triangle vertices: A(" << a1.getX() << "," << a1.getY() 
              << ") B(" << b1.getX() << "," << b1.getY() 
              << ") C(" << c1.getX() << "," << c1.getY() << ")" << std::endl;
    
    // Points inside
    Point inside1(1.0f, 1.0f);
    Point inside2(0.5f, 0.5f);
    std::cout << "  Point (" << inside1.getX() << "," << inside1.getY() << "): " 
              << (bsp(a1, b1, c1, inside1) ? "✅ INSIDE" : "❌ OUTSIDE") << std::endl;
    std::cout << "  Point (" << inside2.getX() << "," << inside2.getY() << "): " 
              << (bsp(a1, b1, c1, inside2) ? "✅ INSIDE" : "❌ OUTSIDE") << std::endl;
    
    // Points outside
    Point outside1(5.0f, 0.0f);
    Point outside2(0.0f, 4.0f);
    std::cout << "  Point (" << outside1.getX() << "," << outside1.getY() << "): " 
              << (bsp(a1, b1, c1, outside1) ? "✅ INSIDE" : "❌ OUTSIDE") << std::endl;
    std::cout << "  Point (" << outside2.getX() << "," << outside2.getY() << "): " 
              << (bsp(a1, b1, c1, outside2) ? "✅ INSIDE" : "❌ OUTSIDE") << std::endl;
    
    // Test 2: Vertices (should be OUTSIDE)
    std::cout << "\n🔸 TEST 2: Vertices (should all be OUTSIDE)" << std::endl;
    std::cout << "  Vertex A: " << (bsp(a1, b1, c1, a1) ? "✅ INSIDE" : "❌ OUTSIDE") << std::endl;
    std::cout << "  Vertex B: " << (bsp(a1, b1, c1, b1) ? "✅ INSIDE" : "❌ OUTSIDE") << std::endl;
    std::cout << "  Vertex C: " << (bsp(a1, b1, c1, c1) ? "✅ INSIDE" : "❌ OUTSIDE") << std::endl;
    
    // Test 3: Edges (should be OUTSIDE)
    std::cout << "\n🔸 TEST 3: Edge points (should all be OUTSIDE)" << std::endl;
    Point edgeAB(2.0f, 0.0f);  // Middle of AB
    Point edgeAC(0.0f, 1.5f);  // Middle of AC
    Point edgeBC(2.0f, 1.5f);  // Middle of BC
    
    std::cout << "  Edge AB (" << edgeAB.getX() << "," << edgeAB.getY() << "): " 
              << (bsp(a1, b1, c1, edgeAB) ? "✅ INSIDE" : "❌ OUTSIDE") << std::endl;
    std::cout << "  Edge AC (" << edgeAC.getX() << "," << edgeAC.getY() << "): " 
              << (bsp(a1, b1, c1, edgeAC) ? "✅ INSIDE" : "❌ OUTSIDE") << std::endl;
    std::cout << "  Edge BC (" << edgeBC.getX() << "," << edgeBC.getY() << "): " 
              << (bsp(a1, b1, c1, edgeBC) ? "✅ INSIDE" : "❌ OUTSIDE") << std::endl;
    
    // Test 4: Equilateral-ish triangle
    std::cout << "\n🔸 TEST 4: Isosceles Triangle A(0,0), B(6,0), C(3,5)" << std::endl;
    Point a2(0.0f, 0.0f);
    Point b2(6.0f, 0.0f);
    Point c2(3.0f, 5.0f);
    
    std::cout << "Triangle vertices: A(" << a2.getX() << "," << a2.getY() 
              << ") B(" << b2.getX() << "," << b2.getY() 
              << ") C(" << c2.getX() << "," << c2.getY() << ")" << std::endl;
    
    Point center(3.0f, 1.67f);  // Near center
    Point tip(3.0f, 4.9f);      // Near top vertex
    Point base(3.0f, 0.1f);     // Near base
    
    std::cout << "  Center (" << center.getX() << "," << center.getY() << "): " 
              << (bsp(a2, b2, c2, center) ? "✅ INSIDE" : "❌ OUTSIDE") << std::endl;
    std::cout << "  Near tip (" << tip.getX() << "," << tip.getY() << "): " 
              << (bsp(a2, b2, c2, tip) ? "✅ INSIDE" : "❌ OUTSIDE") << std::endl;
    std::cout << "  Near base (" << base.getX() << "," << base.getY() << "): " 
              << (bsp(a2, b2, c2, base) ? "✅ INSIDE" : "❌ OUTSIDE") << std::endl;
    
    // Test 5: Negative coordinates
    std::cout << "\n🔸 TEST 5: Triangle with negative coordinates A(-2,-1), B(2,-1), C(0,2)" << std::endl;
    Point a3(-2.0f, -1.0f);
    Point b3(2.0f, -1.0f);
    Point c3(0.0f, 2.0f);
    
    Point origin(0.0f, 0.0f);    // Should be inside
    Point negative(-1.0f, 0.0f); // Should be inside
    Point farOut(5.0f, 5.0f);    // Should be outside
    
    std::cout << "  Origin (" << origin.getX() << "," << origin.getY() << "): " 
              << (bsp(a3, b3, c3, origin) ? "✅ INSIDE" : "❌ OUTSIDE") << std::endl;
    std::cout << "  Negative (" << negative.getX() << "," << negative.getY() << "): " 
              << (bsp(a3, b3, c3, negative) ? "✅ INSIDE" : "❌ OUTSIDE") << std::endl;
    std::cout << "  Far out (" << farOut.getX() << "," << farOut.getY() << "): " 
              << (bsp(a3, b3, c3, farOut) ? "✅ INSIDE" : "❌ OUTSIDE") << std::endl;
    
    // Test 6: Precision test with small triangle
    std::cout << "\n🔸 TEST 6: Small triangle precision test A(0,0), B(0.5,0), C(0.25,0.5)" << std::endl;
    std::cout << "  NOTE: Fixed-point precision (1/256 ≈ 0.0039) may affect very small triangles" << std::endl;
    Point a4(0.0f, 0.0f);
    Point b4(0.5f, 0.0f);
    Point c4(0.25f, 0.5f);
    
    Point tiny1(0.25f, 0.1f);  // Mathematically inside, but may fail due to precision
    Point tiny2(0.25f, 0.49f); // Mathematically inside, but may fail due to precision
    Point tiny3(0.25f, 0.51f); // Should be outside
    
    std::cout << "  Tiny1 (" << tiny1.getX() << "," << tiny1.getY() << "): " 
              << (bsp(a4, b4, c4, tiny1) ? "✅ INSIDE" : "❌ OUTSIDE (precision limit)") << std::endl;
    std::cout << "  Tiny2 (" << tiny2.getX() << "," << tiny2.getY() << "): " 
              << (bsp(a4, b4, c4, tiny2) ? "✅ INSIDE" : "❌ OUTSIDE (precision limit)") << std::endl;
    std::cout << "  Tiny3 (" << tiny3.getX() << "," << tiny3.getY() << "): " 
              << (bsp(a4, b4, c4, tiny3) ? "✅ INSIDE" : "❌ OUTSIDE") << std::endl;
    
    return 0;
}
/* int main() {
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
} */
