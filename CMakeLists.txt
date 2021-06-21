cmake_minimum_required(VERSION 3.17)
project(AplicatieLivrari)

set(CMAKE_CXX_STANDARD 14)

add_executable(AplicatieLivrari main.cpp Repo/RepoTemp.h Entitites/Entity.h Entitites/Order.cpp Entitites/Order.h Entitites/Courier.cpp Entitites/Courier.h Entitites/Restaurant.cpp Entitites/Restaurant.h Entitites/Client.cpp Entitites/Client.h Entitites/IdGenerator.h Entitites/EntityType.h Tests/testGenerateId.cpp Tests/testGenerateId.h Service/ClientService.cpp Service/ClientService.h Service/MasterService.h Service/CourierService.cpp Service/CourierService.h Service/OrderService.cpp Service/OrderService.h Service/RestaurantService.cpp Service/RestaurantService.h Tests/TestEntities.h Tests/TestRepo.h Tests/runTests.h Tests/testService.h UI/UI.cpp UI/UI.h Validator/ClientValidator.h Exceptions/ValidationException.h Exceptions/ExistingIdException.h Exceptions/NonExistingIdException.h Validator/NameValidator.h)