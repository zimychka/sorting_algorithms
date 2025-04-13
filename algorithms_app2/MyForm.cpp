#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
// <>^ - автоматическая очистка памяти
int main(array<String^>^ args) {
	Application::SetCompatibleTextRenderingDefault(false); // корректная обработка текста
	Application::EnableVisualStyles(); // подключаем визуальные стили
	algorithmsapp2::MyForm form; // создание объекта
	Application::Run(% form); // запуск формы. отсылка через %, потому что класс "по ссылке"
}
