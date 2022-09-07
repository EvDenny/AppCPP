

class Shape {
  constructor(name) {
    this.name = name;
  }
  getName() {
    return this.name;
  }
  setName(value) {
    this.name = value;
  }
  setHeight(value) {
    if (value < 0) {
      throw new Error("Height cannot be negative");
    }
    this.height = value;
  }
}

class Rectangle extends Shape {
  constructor(name, width, height) {
    super("Rectangle");
    this.width = width;
    this.height = height;
  }
  setWidth(value) {
    if (value < 0) {
      throw new Error("Width cannot be negative");
    }
    this.width = value;
  }
  getWidth() {
    return this.width;
  }
  setHeight(value) {
    if (value < 0) {
      throw new Error("Height cannot be negative");
    }
    this.height = value;
  }
  getHeight() {
    return this.height;
  }
  getArea() {
    return this.width * this.height;
  }
  getPerimeter() {
    return 2 * (this.width + this.height);
  }
}

class Square extends Rectangle {
  constructor(name, side) {
    super("Square", side);
  }
  setSide(value) {
    super.setSide(value);
    this.side = value;
  }
  getSide() {
    return this.side;
  }
  getArea() {
    return this.side ** 2;
  }
  getPerimeter() {
    return 4 * this.side;
  }
}

class Circle extends Shape {
  constructor(radius) {
    super("Circle");
    this.radius = radius;
  }
  getArea() {
    return Math.PI * this.radius * this.radius;
  }
  setRadius(value) {
    if (value < 0) {
      throw new Error("Radius cannot be negative");
    }
    this.radius = value;
  }
}

const rect = new Rectangle("Rectangle1", 20, 20);
