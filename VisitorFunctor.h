class VistorFunctor {
   Visitor &visitor;
public:

  VisitorFunctor(Visitor& v) : visitor(v) {}

  void operator()(Node& node)
  {
     return node.accept(visitor);
  }
};
