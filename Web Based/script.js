let employees = JSON.parse(localStorage.getItem("employees")) || [];
let editIndex = -1;

function isAlpha(v){ return /^[A-Za-z ]+$/.test(v); }
function isNumeric(v){ return /^[0-9]+$/.test(v); }

function calculate(b,a,d,h,r){
    let ot = h * r;
    let tax = b * 0.05;
    let net = b + a + ot - tax - d;
    return { ot, tax, net };
}

function clearErrors(){
    errorGeneral.textContent="";
    errorGrade.textContent="";
    errorCNIC.textContent="";
}

function addEmployee(){
    clearErrors();

    let id = val("id");
    let name = val("empName");
    let father = val("father");
    let cnic = val("cnic");
    let dept = val("department");
    let grade = val("grade");
    let date = val("date");

    let basic = num("basic");
    let allowance = num("allowance");
    let deduction = num("deduction");
    let otH = num("otHours");
    let otR = num("otRate");

    if(!id || !name || !father || !cnic || !dept || !grade || !date){
        errorGeneral.textContent="All fields are required";
        return;
    }

    if(!isAlpha(name) || !isAlpha(father) || !isAlpha(dept)){
        errorGeneral.textContent="Name, Father & Department must be alphabets only";
        return;
    }

    if(!isNumeric(cnic)){
        errorCNIC.textContent="CNIC must be numeric only";
        return;
    }

    if(!/^[A-Za-z]$/.test(grade)){
        errorGrade.textContent="Grade must be a single letter";
        return;
    }

    if(employees.some(e=>e.id===id)){
        errorGeneral.textContent="Employee ID already exists";
        return;
    }

    let c = calculate(basic, allowance, deduction, otH, otR);

    employees.push({
        id,name,father,cnic,dept,grade,date,
        basic,allowance,deduction,
        otH,otR,
        ot:c.ot,
        tax:c.tax,
        net:c.net
    });

    save();
    clearForm();
}

function searchEmployee(){
    let sid = val("searchId");
    let emp = employees.find(e=>e.id===sid);
    if(!emp){ alert("Employee not found"); return; }
    editIndex = employees.indexOf(emp);
    fill(emp);
}

function updateEmployee(){
    if(editIndex===-1){
        alert("Search employee first");
        return;
    }
    employees.splice(editIndex,1);
    editIndex=-1;
    addEmployee();
}

function removeEmp(i){
    employees.splice(i,1);
    save();
}

function save(){
    localStorage.setItem("employees",JSON.stringify(employees));
    render();
}

function render(){
    tableBody.innerHTML="";
    employees.forEach((e,i)=>{
        tableBody.innerHTML+=`
        <tr>
            <td>${e.id}</td>
            <td>${e.name}</td>
            <td>${e.dept}</td>
            <td>${e.basic}</td>
            <td>${e.allowance}</td>
            <td>${e.deduction}</td>
            <td>${e.otH}</td>
            <td>${e.ot}</td>
            <td>${e.tax}</td>
            <td>${e.net}</td>
            <td><button class="action" onclick="removeEmp(${i})">Delete</button></td>
        </tr>`;
    });
}

function fill(e){
    id.value=e.id;
    empName.value=e.name;
    father.value=e.father;
    cnic.value=e.cnic;
    department.value=e.dept;
    grade.value=e.grade;
    date.value=e.date;
    basic.value=e.basic;
    allowance.value=e.allowance;
    deduction.value=e.deduction;
    otHours.value=e.otH;
    otRate.value=e.otR;
}

function clearForm(){
    document.querySelectorAll("input").forEach(i=>i.value="");
}

function val(id){ return document.getElementById(id).value.trim(); }
function num(id){ return Number(document.getElementById(id).value); }

render();
