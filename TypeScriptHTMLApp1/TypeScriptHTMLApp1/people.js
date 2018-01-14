var person = (function () {
    function person(name, age) {
        this.name = name;
        this.age = age;
    }
    person.prototype.getname = function () {
        return this.name;
    };
    person.prototype.getage = function () {
        return this.age;
    };
    person.prototype.gettitle = function () {
        return this.name;
    };
    return person;
}());
//# sourceMappingURL=people.js.map